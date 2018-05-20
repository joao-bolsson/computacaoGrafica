/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
****************************************************************************/

//Baseado no demo C:\Qt\Qt5.5.1\Examples\Qt-5.5\opengl\qopenglwidget

#include "mainwindow.h"

#include <QApplication>
#include <QGroupBox>
#include <QGridLayout>

MainWindow::MainWindow()
{
    Canvas2D *canvas = new Canvas2D(this);

    //****************************************************
    //cria os Layouts
    //****************************************************

    QHBoxLayout *horizontalLayout = new QHBoxLayout;

    QGroupBox *updateGroupBox = new QGroupBox(this);
    updateGroupBox->setLayout(horizontalLayout);
    updateGroupBox->setTitle("Ferramentas");

    QGridLayout *gridCanvas = new QGridLayout;
    gridCanvas->addWidget(canvas, 0, 0, 1, 1);

    QGroupBox *boxCanvas = new QGroupBox(this);
    boxCanvas->setLayout(gridCanvas);
    boxCanvas->setTitle("Canvas");

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(boxCanvas, 0, 0, 2, 1);
    gridLayout->addWidget(updateGroupBox, 2, 0, 1, 1); //row, column, rowSpan, colSpan

    QGroupBox * groupBox = new QGroupBox(this);
    groupBox->setLayout(gridLayout);
    setCentralWidget(groupBox);

    //o timer eh usado para controlar o refresh de tela, via SLOT(update()) abaixo. Ele nao faz controle de FPS
    m_timer = new QTimer(this);
    m_timer->setInterval(10);
    m_timer->start();

    //tratamento de eventos de menu, checkbox, timer, botao, slider e QSpinBox (e etc)
    connect(m_timer, SIGNAL(timeout()), canvas, SLOT(update()));
}
