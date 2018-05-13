
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
#include <list>
#include <vector>
#include "rectangle.h"

using namespace std;

bool drawLine = false, drawRectangle = false;
bool mouseMoved = false;
list<Shape*> shapes;

// pressed point on canvas
vector<Point> points;

Shape* demo = new Shape();
Shape* selectedShape = new Shape();

Point mousePointPressed = Point(-1, -1);

// *******************************************************************************
//Coloque seu codigo aqui, usando as funcoes da Canvas2D defindas na classe Canvas2D (arquivo glCanvas2d.h).
// *******************************************************************************
void Canvas2D::paintGL() //callback de desenho na canvas. Chamado pelo Timer definido em mainWindow.cpp
{
    list<Shape*>::iterator it;
    for (it = shapes.begin(); it != shapes.end(); it++) {
        Shape *shape = (*it);
        shape->draw(this);
        if (shape->isSelected(mousePointPressed)) {
            selectedShape = shape;
        }
    }

    demo->draw(this);
    demo->drawSelectionBox(this);
    selectedShape->drawSelectionBox(this);
}

void Canvas2D::wheelEvent(QWheelEvent *event) //callback de mouse
{
    qDebug("Mouse Wheel event %d", event->delta() );
}

void Canvas2D::mousePressEvent(QMouseEvent *event) //callback de mouse
{
    //seta o foco para a canvas2D, desse modo pode-se pegar eventos de teclado dentro da canvas.
    setFocus();

    Point point = Point(event->x(), (event->y() - height()) * -1);
    // apenas adiciona pontos se tiver alguma coisa sendo desenhada
    if (drawLine || drawRectangle) {
        points.push_back(point);
    } else {
        selectedShape = new Shape();
        mousePointPressed = point;
    }
}

void clearSelection() {
    mousePointPressed = Point(-1, -1);
    selectedShape = new Shape();
}

void stopDrawing() {
    points.clear();
    drawLine = false;
    drawRectangle = false;
    mouseMoved = false;
    demo = new Shape();
}

void Canvas2D::mouseReleaseEvent(QMouseEvent *event) //callback de mouse
{
    if (!mouseMoved) {
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

    qDebug("\nMouse Release: %d %d", event->x(), event->y());
}

void Canvas2D::mouseMoveEvent(QMouseEvent * event) //callback de mouse
{
    mouseMoved = true;
    // desenha uma previa
    if (points.size() > 0) {
        Point p1 = points[0];

        if (drawLine) {
            demo = new Line(p1, Point(event->x(), (event->y() - height()) * -1));
        } else if (drawRectangle) {
            demo = new RectangleC(p1, Point(event->x(), (event->y() - height()) * -1));
        }
    }
    qDebug("\nMouse Move: %d %d", event->x(), event->y());
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
    clearSelection();
}

void Canvas2D::btnRotateLeft() {
    // TODO
    clearSelection();
    drawLine = false;
    drawRectangle = false;
}

void Canvas2D::btnRotateRight() {
    // TODO
    clearSelection();
    drawLine = false;
    drawRectangle = false;
}
