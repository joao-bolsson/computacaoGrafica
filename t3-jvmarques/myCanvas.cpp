
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
#include "cube.h"

using namespace std;

vector<Solid*> solids;

Cube *cube = new Cube(150, new Point(300, 200, 0));

void Canvas2D::paintGL() //callback de desenho na canvas. Chamado pelo Timer definido em mainWindow.cpp
{
    cube->draw(this);
}

void Canvas2D::wheelEvent(QWheelEvent *event) //callback de mouse
{
    // empty
}

void Canvas2D::mousePressEvent(QMouseEvent *event) //callback de mouse
{
    //seta o foco para a canvas2D, desse modo pode-se pegar eventos de teclado dentro da canvas.
    setFocus();
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
    char key = (char) event->key();
    cube->rotate(key);
}
