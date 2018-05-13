
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
#include "line.h"

using namespace std;

bool drawLine = false;
list<Shape*> shapes;

// pressed point on canvas
vector<Point> points;

// *******************************************************************************
//Coloque seu codigo aqui, usando as funcoes da Canvas2D defindas na classe Canvas2D (arquivo glCanvas2d.h).
// *******************************************************************************
void Canvas2D::paintGL() //callback de desenho na canvas. Chamado pelo Timer definido em mainWindow.cpp
{
    this->color(0, 0, 0);
    list<Shape*>::iterator it;
    for (it = shapes.begin(); it != shapes.end(); it++) {
        (*it)->draw(this);
    }
}

void Canvas2D::wheelEvent(QWheelEvent *event) //callback de mouse
{
    qDebug("Mouse Wheel event %d", event->delta() );
}

void Canvas2D::mousePressEvent(QMouseEvent *event) //callback de mouse
{
    //seta o foco para a canvas2D, desse modo pode-se pegar eventos de teclado dentro da canvas.
    setFocus();

    qDebug("\nMouse Press: %d %d", event->x(), event->y());

    points.push_back(Point(event->x(), event->y()));

    if (drawLine && points.size() == 2) {
        Point p1 = points[0];
        Point p2 = points[1];
        shapes.push_back(new Line(p1, p2));
        points.clear();

        qDebug("Points size: %d", points.size());
    }
}

void Canvas2D::mouseReleaseEvent(QMouseEvent *event) //callback de mouse
{
    qDebug("\nMouse Release: %d %d", event->x(), event->y());
}

void Canvas2D::mouseMoveEvent(QMouseEvent * event) //callback de mouse
{
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
    drawLine = !drawLine;
    qDebug("draw line: %s", (drawLine ? "true" : "false"));
}
