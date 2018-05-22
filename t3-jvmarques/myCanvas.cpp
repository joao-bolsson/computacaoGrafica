
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
#include <vector>
#include "cube.h"

using namespace std;

vector<Solid*> solids;

void Canvas2D::paintGL() //callback de desenho na canvas. Chamado pelo Timer definido em mainWindow.cpp
{
    for (auto s : solids) {
        s->draw(this);
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

    Point *mousePoint = new Point(event->x(), (event->y() - height()) * -1);

    Cube *cube = new Cube(100, mousePoint);
    solids.push_back(cube);
}

void Canvas2D::mouseReleaseEvent(QMouseEvent *event) //callback de mouse
{
    // empty
}

void Canvas2D::mouseMoveEvent(QMouseEvent * event) //callback de mouse
{
    // empty
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
    // empty
}
