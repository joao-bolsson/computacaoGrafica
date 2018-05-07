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
#include <QPushButton>

MainWindow::MainWindow()
{
    Canvas2D *canvas = new Canvas2D(this);

    //****************************************************
    //cria os Layouts
    //****************************************************

    QGroupBox * groupBox = new QGroupBox(this);

    QGroupBox *boxTools = new QGroupBox(this);
    boxTools->setTitle("Ferramentas");
    QGridLayout *gridLayout_2= new QGridLayout(boxTools);
    gridLayout_2->setSpacing(6);
    gridLayout_2->setContentsMargins(11, 11, 11, 11);

    QPushButton *btnQuad = new QPushButton(boxTools);
    QPushButton *btnRectangle = new QPushButton(boxTools);
    QPushButton *btnLine = new QPushButton(boxTools);
    QPushButton *btnCurve = new QPushButton(boxTools);

    gridLayout_2->addWidget(btnQuad, 0, 0, 1, 1);
    gridLayout_2->addWidget(btnRectangle, 0, 1, 1, 1);
    gridLayout_2->addWidget(btnLine, 0, 2, 1, 1);
    gridLayout_2->addWidget(btnCurve, 0, 3, 1, 1);

    QGroupBox *boxRotation = new QGroupBox(this);
    QGridLayout *gridRotation = new QGridLayout(boxRotation);
    gridRotation->setSpacing(6);
    gridRotation->setContentsMargins(11, 11, 11, 11);

    QPushButton *pushButton_5 = new QPushButton(boxRotation);
    QPushButton *pushButton_6 = new QPushButton(boxRotation);

    gridRotation->addWidget(pushButton_5, 0, 0, 1, 1);
    gridRotation->addWidget(pushButton_6, 0, 1, 1, 1);

    QGroupBox *boxOptions = new QGroupBox(this);
    QGridLayout *gridLayout_3 = new QGridLayout(boxOptions);
    gridLayout_3->setSpacing(6);
    gridLayout_3->setContentsMargins(11, 11, 11, 11);

    QPushButton *btnClear = new QPushButton(boxOptions);
    QPushButton *btnOpen = new QPushButton(boxOptions);
    QPushButton *btnSave = new QPushButton(boxOptions);

    gridLayout_3->addWidget(btnClear, 0, 0, 1, 1);
    gridLayout_3->addWidget(btnOpen, 0, 1, 1, 1);
    gridLayout_3->addWidget(btnSave, 0, 2, 1, 1);

    boxTools->setTitle("Ferramentas");
    btnQuad->setText("Quadrado");
    btnRectangle->setText("Retângulo");
    btnLine->setText("Linha");
    btnCurve->setText("Curva");
    boxRotation->setTitle("Rotação");
    pushButton_5->setText("Esquerda");
    pushButton_6->setText("Direita");
    boxOptions->setTitle("Opções");
    btnClear->setText("Limpar");
    btnOpen->setText("Abrir");
    btnSave->setText("Salvar");

    QGridLayout *gridCanvas = new QGridLayout;
    gridCanvas->addWidget(canvas, 0, 0, 1, 1);

    QGroupBox *boxCanvas = new QGroupBox(this);
    boxCanvas->setLayout(gridCanvas);
    boxCanvas->setTitle("Canvas");

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(boxCanvas, 0, 0, 5, 3);
    gridLayout->addWidget(boxTools, 5, 0, 1, 1);
    gridLayout->addWidget(boxRotation, 5, 1, 1, 1);
    gridLayout->addWidget(boxOptions, 5, 2, 1, 1);

    groupBox->setLayout(gridLayout);
    setCentralWidget(groupBox);

    //o timer eh usado para controlar o refresh de tela, via SLOT(update()) abaixo. Ele nao faz controle de FPS
    m_timer = new QTimer(this);
    m_timer->setInterval(10);
    m_timer->start();

    //tratamento de eventos de menu, checkbox, timer, botao, slider e QSpinBox (e etc)
    connect(m_timer, SIGNAL(timeout()), canvas, SLOT(update()));
}
