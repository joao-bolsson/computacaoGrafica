
// *********************************************************************
// Canvas para desenho - Versao C.
//  Autor: Cesar Tadeu Pozzer
//         07/2016
//
//  Pode ser utilizada para fazer desenhos ou animacoes, como jogos simples.
//  Tem tratamento de mosue
// *
// *   pozzer@inf.ufsm.br
// *   pozzer3@gmail.com
// *
//

#include "glCanvas2d.h"
#include "mainwindow.h"

#include <math.h>
#include <QMessageBox>
#include <QWheelEvent>
#include "rectangle.h"
#include "curve.h"
#include <iostream>
#include <fstream>

using namespace std;

bool drawLine = false, drawRectangle = false, drawCurve = false;
bool mouseMoved = false;
vector<Shape*> shapes;

// pressed point on canvas
vector<Point> points;

Shape* demo = new Shape();
Shape* selectedShape = new Shape();
Shape* shapeCopy = new Shape();

Point mousePointPressed = Point(-1, -1);

Point selectedPointCopy = Point(-1, -1);

// index do ponto de controle da curva que esta sendo editado -2: nenhum sendo editado
int index = -2;

// *******************************************************************************
//Coloque seu codigo aqui, usando as funcoes da Canvas2D defindas na classe Canvas2D (arquivo glCanvas2d.h).
// *******************************************************************************
void Canvas2D::paintGL() //callback de desenho na canvas. Chamado pelo Timer definido em mainWindow.cpp
{
    for (unsigned int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw(this);
    }

    demo->draw(this);
    demo->drawSelectionBox(this);
    selectedShape->drawSelectionBox(this);

    if (drawCurve) {
        // desenha os pontos de controle
        for (unsigned int i = 0; i < points.size(); i++) {
            color(1, 0, 0);
            circleFill(points[i].getX(), points[i].getY(), 5, 10);
        }
    }
}

void Canvas2D::wheelEvent(QWheelEvent *event) //callback de mouse
{
    qDebug("Mouse Wheel event %d", event->delta() );
}

void stopDrawing() {
    points.clear();
    drawLine = false;
    drawRectangle = false;
    mouseMoved = false;
    drawCurve = false;
    demo = new Shape();
    shapeCopy = new Shape();
    selectedPointCopy = Point(-1, -1);
    index = -2;
}

void Canvas2D::mousePressEvent(QMouseEvent *event) //callback de mouse
{
    //seta o foco para a canvas2D, desse modo pode-se pegar eventos de teclado dentro da canvas.
    setFocus();

    Point point = Point(event->x(), (event->y() - height()) * -1);
    // apenas adiciona pontos se tiver alguma coisa sendo desenhada
    if (drawLine || drawRectangle || drawCurve) {
        points.push_back(point);

        if (drawCurve && points.size() == 4) {
            Curve *curve = new Curve();

            for (unsigned int i = 0; i < points.size(); i++) {
                curve->addPoint(new Point(points[i].getX(), points[i].getY()));
            }

            shapes.push_back(curve);
            stopDrawing();
        }
    } else {
        selectedShape = new Shape();
        mousePointPressed = point;

        for (unsigned int i = 0; i < shapes.size(); i++) {
            if (shapes[i]->isSelected(mousePointPressed)) {
                selectedShape = shapes[i];
            }
        }
    }
}

void clearSelection() {
    mousePointPressed = Point(-1, -1);
    selectedShape = new Shape();
    selectedPointCopy = Point(-1, -1);
    index = -2;
}

void Canvas2D::mouseReleaseEvent(QMouseEvent *event) //callback de mouse
{
    shapeCopy = new Shape();
    selectedPointCopy = Point(-1, -1);
    index = -2;
    if (!mouseMoved && !drawCurve) {
        stopDrawing();
    }

    // apenas adiciona pontos se tiver alguma coisa sendo desenhada
    if (drawLine || drawRectangle) {
        points.push_back(Point(event->x(), (event->y() - height()) * -1));

        if (points.size() == 2) {
            Point p1 = points[0];
            Point p2 = points[1];
            if (drawLine) {
                shapes.push_back(new Line(p1, p2));
            } else if (drawRectangle) {
                shapes.push_back(new RectangleC(p1, p2));
            }
            stopDrawing();
        }
    }
}

void Canvas2D::mouseMoveEvent(QMouseEvent * event) //callback de mouse
{
    mouseMoved = true;
    Point mousePoint = Point(event->x(), (event->y() - height()) * -1);
    // desenha uma previa
    if (points.size() > 0) {
        Point p1 = points[0];

        if (drawLine) {
            demo = new Line(p1, mousePoint);
        } else if (drawRectangle) {
            demo = new RectangleC(p1, mousePoint);
        }
    } else {
        // move figura selecionada

        // shapeCopy é feita com base na shape selecionada onde o mouse foi clicado
        // shapeCp é usada como auxiliar para fazer o calculo de translacao
        // shapeCopy soh eh sobrescrito quando o mouse for largado
        if (shapeCopy->getId() == SHAPE) {
            Shape *cp = selectedShape->copy();
            shapeCopy = cp;
        }

        if (Curve *curve = dynamic_cast<Curve*>(selectedShape)) {
            Curve* shapeCp = dynamic_cast<Curve*>(shapeCopy);

            int width = mousePointPressed.getX() - mousePoint.getX();
            int height = mousePointPressed.getY() - mousePoint.getY();

            // verifica se nao ta editando um ponto de control

            if (index == -2) {
                // verifica apenas se nao tiver editando um ponto de controle
                index = curve->isSelectedPointCtrl(mousePointPressed);
            }

            if (index != -1) {
                // move ponto de controle
                if (selectedPointCopy.getX() == -1 && selectedPointCopy.getY() == -1) {
                    Point *p = curve->getControlPts()[index];

                    selectedPointCopy = Point(p->getX(), p->getY());
                }

                curve->changePoint(index, selectedPointCopy.getX() - width, selectedPointCopy.getY() - height);
            } else {
                if (Curve* curveCopy = dynamic_cast<Curve*>(shapeCp)) {
                    vector<Point*> ptsCp = curveCopy->getControlPts();
                    for (unsigned int i = 0; i < ptsCp.size(); i++) {
                        Point *p = ptsCp[i];
                        curve->changePoint(i, p->getX() - width, p->getY() - height);
                    }
                }
            }
        } else if (Line* line = dynamic_cast<Line*>(selectedShape)) {
            Line* shapeCp = dynamic_cast<Line*>(shapeCopy);

            Point p1 = shapeCp->getP1();
            Point p2 = shapeCp->getP2();

            int width = mousePointPressed.getX() - mousePoint.getX();
            int height = mousePointPressed.getY() - mousePoint.getY();

            line->setP1(Point(p1.getX() - width, p1.getY() - height));
            line->setP2(Point(p2.getX() - width, p2.getY() - height));

            if (RectangleC* rect = dynamic_cast<RectangleC*>(line)) {
                if (RectangleC* rectCopy = dynamic_cast<RectangleC*>(shapeCp)) {
                    Point p3 = rectCopy->getP3();
                    Point p4 = rectCopy->getP4();

                    rect->setP3(Point(p3.getX() - width, p3.getY() - height));
                    rect->setP4(Point(p4.getX() - width, p4.getY() - height));
                }
            }

        }
    }
}

//callback para botao definido na mainWindow.
void Canvas2D::showMsg()
{
    QMessageBox* msg = new QMessageBox(this);
    msg->setText("Msg GlWidget");
    msg->show();
}

void Canvas2D::keyPressEvent(QKeyEvent* event)
{
    qDebug("\nTecla pessionada  %d", event->key() );
}

void Canvas2D::btnLine() {
    drawLine = true;
    drawRectangle = false;
    clearSelection();
}

void Canvas2D::btnClear() {
    stopDrawing();
    shapes.clear();
    clearSelection();
}

void Canvas2D::btnRectangle() {
    drawRectangle = true;
    drawLine = false;
    drawCurve = false;
    clearSelection();
}

/**
 * @param d If true - rotate to the left, false - right.
 * @param shape
 */
void rotate(bool d, Shape *shape) {
    Point pivo = shape->getPivo();

    // leva para a origem
    shape->translate(-pivo.getX(), -pivo.getY());

    // rotaciona
    shape->rotate(d);

    // leva de volta
    shape->translate(pivo.getX(), pivo.getY());

    shapeCopy = shape->copy();
}

void Canvas2D::btnRotateLeft() {
    drawLine = false;
    drawRectangle = false;
    drawCurve = false;
    rotate(true, selectedShape);
}

void Canvas2D::btnRotateRight() {
    drawLine = false;
    drawRectangle = false;
    drawCurve = false;
    rotate(false, selectedShape);
}

void Canvas2D::btnCurve() {
    clearSelection();
    drawLine = false;
    drawRectangle = false;
    drawCurve = true;
}

string filePath = "./teste.jv";
fstream file;

void Canvas2D::btnOpen() {
    btnClear();

    file.open(filePath, ios::in | ios::binary);

    if (!file) exit(2);

    unsigned int size;
    file.read(reinterpret_cast<char *>(&size), sizeof(size));

    for (unsigned int i = 0; i < size; i++) {
        byte id;
        file.read(reinterpret_cast<char *>(&id), sizeof(id));

        Shape *shape;
        switch(id) {
        case LINE: {
            int p[4];
            file.read(reinterpret_cast<char *>(p), 4 * sizeof(int));

            shape = new Line(Point(p[0], p[1]), Point(p[2], p[3]));
            break;
        }
        case RECTANGLE: {
            int p[8];
            file.read(reinterpret_cast<char *>(p), 8 * sizeof(int));

            RectangleC *rect = new RectangleC(Point(p[0], p[1]), Point(p[2], p[3]));
            rect->setP3(Point(p[4], p[5]));
            rect->setP4(Point(p[6], p[7]));

            shape = rect;
            break;
        }
        case CURVE: {
            // numero de pontos de controle da curva
            unsigned int sizeCtrl;
            file.read(reinterpret_cast<char *>(&sizeCtrl), sizeof(sizeCtrl));

            // a cada dois int eh um point
            int pAux[sizeCtrl * 2];

            file.read(reinterpret_cast<char *>(pAux), sizeCtrl * 2 * sizeof(int));

            Curve* curve = new Curve();

            for (unsigned int j = 0; j < (sizeCtrl * 2); j++) {
                int x = pAux[j];
                int y = pAux[++j];

                curve->addPoint(new Point(x, y));
            }

            shape = curve;
            break;
        }
        }
        shapes.push_back(shape);
    }

    file.close();
}

void Canvas2D::btnSave() {
    auto size = (unsigned int) shapes.size();
    file.open(filePath, ios::out | ios::binary);

    if (!file) exit(1);

    // grava o número de shapes
    file.write(reinterpret_cast<char *>(&size), sizeof(size));

    for (unsigned int i = 0; i < shapes.size(); i++) {
        Shape *shape = shapes[i];

        // grava o id da shape
        byte id = shape->getId();
        file.write(reinterpret_cast<char *>(&id), sizeof(id));

        switch(id) {
        case LINE: {
            Line* line = dynamic_cast<Line*>(shape);

            int p[4];

            p[0] = line->getP1().getX();
            p[1] = line->getP1().getY();
            p[2] = line->getP2().getX();
            p[3] = line->getP1().getX();

            file.write(reinterpret_cast<char *>(p), 4 * sizeof(int));
            break;
        }
        case RECTANGLE: {
            RectangleC* rect = dynamic_cast<RectangleC*>(shape);

            // escreve os 4 pontos do retangulo

            int p[8];
            p[0] = rect->getP1().getX();
            p[1] = rect->getP1().getY();

            p[2] = rect->getP2().getX();
            p[3] = rect->getP2().getY();

            p[4] = rect->getP3().getX();
            p[5] = rect->getP3().getY();

            p[6] = rect->getP4().getX();
            p[7] = rect->getP4().getY();

            file.write(reinterpret_cast<char *>(p), 8 * sizeof(int));
            break;
        }
        case CURVE: {
            Curve* curve = dynamic_cast<Curve*>(shape);

            vector<Point*> ctrlPoints = curve->getControlPts();
            // numero de pontos de controle
            unsigned int sizeCtrl = ctrlPoints.size();

            file.write(reinterpret_cast<char *>(&sizeCtrl), sizeof(sizeCtrl));

            int pAux[sizeCtrl * 2];
            int index = 0;
            // insere pontos de controle
            for (unsigned int j = 0; j < ctrlPoints.size(); j++) {
                Point *p = ctrlPoints[j];

                pAux[index] = p->getX();
                pAux[++index] = p->getY();
                index++;
            }
            file.write(reinterpret_cast<char *>(pAux), sizeCtrl * 2 * sizeof(int));
            break;
        }
        }

    }

    file.flush();
    file.close();
}

void Canvas2D::btnDelete() {
    if (selectedShape->getId() != SHAPE) {
        for (unsigned int i = 0; i < shapes.size(); i++) {
            if (shapes[i] == selectedShape) {
                shapes.erase(shapes.begin() + i);
                stopDrawing();
                clearSelection();
                return;
            }
        }
    }
}

