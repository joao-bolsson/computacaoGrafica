
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
}

void Canvas2D::mouseReleaseEvent(QMouseEvent *event) //callback de mouse
{
    shapeCopy = new Shape();
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

        if (Line* line = dynamic_cast<Line*>(selectedShape)) {

            Line* shapeCp = dynamic_cast<Line*>(shapeCopy);

            if (!shapeCp) {
                if (RectangleC* rect = dynamic_cast<RectangleC*>(line)) {
                    shapeCopy = new RectangleC(rect->getP1(), rect->getP2());
                    shapeCp = new RectangleC(rect->getP1(), rect->getP2());
                } else {
                    shapeCopy = new Line(line->getP1(), line->getP2());
                    shapeCp = new Line(line->getP1(), line->getP2());
                }
            }

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

void translate(Shape *shape, int x, int y) {
    // nao precisa transladar o pivo pois nele nada se altera
    if (Line* line = dynamic_cast<Line*>(shape)) {
        Point p2 = line->getP2();
        line->setP2(Point(p2.getX() + x, p2.getY() + y));

        if (RectangleC* rect = dynamic_cast<RectangleC*>(line)) {
            Point p3 = rect->getP3();
            Point p4 = rect->getP4();

            rect->setP3(Point(p3.getX() + x, p3.getY() + y));
            rect->setP4(Point(p4.getX() + x, p4.getY() + y));
        }
    }
}

/**
 * @param d If true - rotate to the left, false - right.
 * @param shape
 */
void rotate(bool d, Shape *shape) {
    if (Line* line = dynamic_cast<Line*>(shape)) {
        Point p1 = line->getP1(); // pivo
        // leva para a origem
        translate(shape, -p1.getX(), -p1.getY());

        vector<Point> shapePoints;
        shapePoints.push_back(line->getP2());

        if (RectangleC* rect = dynamic_cast<RectangleC*>(line)) {
            shapePoints.push_back(rect->getP3());
            shapePoints.push_back(rect->getP4());
        }

        int factor = -1;
        if (d) {
            factor = 1;
        }

        for (unsigned int i = 0; i < shapePoints.size(); i++) {
            Point p = shapePoints[i];

            double x = p.getX() * cos(0.08) - factor * p.getY() * sin(0.08);
            double y = factor * p.getX() * sin(0.08) + p.getY() * cos(0.08);

            shapePoints[i] = Point(x, y);
        }

        line->setP2(shapePoints[0]);

        if (RectangleC* rect = dynamic_cast<RectangleC*>(line)) {
            rect->setP3(shapePoints[1]);
            rect->setP4(shapePoints[2]);
        }

        // leva de volta
        translate(shape, p1.getX(), p1.getY());

        // faz a mesma coisa para as copias (pode mover objeto rotacionado, apenas linha)
        if (Line* lineCopy = dynamic_cast<Line*>(shapeCopy)) {
            lineCopy->setP2(line->getP2());
        }
    }
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
    file.open(filePath, ios::in | ios::binary);

        if (!file) exit(2);

        unsigned int size;
        file.read(reinterpret_cast<char *>(&size), sizeof(size));

        qDebug("Shapes: %d", size);

//        signed short v[size];

//        file.read(reinterpret_cast<char *>(v), sizeof(v));
        file.close();

//        vector<short> signals;

//        for (auto a : v) {
//            cout << a << endl;
//            signals.push_back(a);
//        }
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

