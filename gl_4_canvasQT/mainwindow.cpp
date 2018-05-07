/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
****************************************************************************/

//Baseado no demo C:\Qt\Qt5.5.1\Examples\Qt-5.5\opengl\qopenglwidget

#include "mainwindow.h"

#include <QApplication>
#include <QMenuBar>
#include <QStatusBar>
#include <QGroupBox>
#include <QSlider>
#include <QLabel>
#include <QCheckBox>
#include <QSpinBox>
#include <QScrollArea>
#include <QMessageBox>
#include <QResizeEvent>
#include <QListWidget>
#include <QGridLayout>

MainWindow::MainWindow()
{
    Canvas2D *canvas = new Canvas2D(this);

    QLabel *label = new QLabel(this);
    label->setText("A scrollable QOpenGLWidget");
    label->setAlignment(Qt::AlignHCenter);

    QSlider *slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(0, 50);
    slider->setSliderPosition(30);

    refreshRate = new QSpinBox(this);
    refreshRate->setSuffix(" ms");
    refreshRate->setValue(10);
    refreshRate->setSingleStep(10);
    refreshRate->setToolTip("Dica do que o componente faz");

    QCheckBox *timerBased = new QCheckBox("Use timer", this);
    timerBased->setChecked(true);
    timerBased->setToolTip("Toggles using a timer to trigger update()");

    QLabel *updateLabel = new QLabel("Tempo de Espera entre updates da Canvas");

    //****************************************************
    //cria os Layouts
    //****************************************************

    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(updateLabel);
    horizontalLayout->addWidget(refreshRate);
    horizontalLayout->addWidget(timerBased);

    QGroupBox *updateGroupBox = new QGroupBox(this);
    updateGroupBox->setLayout(horizontalLayout);
    updateGroupBox->setTitle("Ferramentas");

    QGridLayout *gridCanvas = new QGridLayout;
    gridCanvas->addWidget(canvas, 0, 0, 1, 1);

    QGroupBox *boxCanvas = new QGroupBox(this);
    boxCanvas->setLayout(gridCanvas);
    boxCanvas->setTitle("Canvas");

    QGridLayout *gridLayout = new QGridLayout;// Pozzer: aqui estava QGridLayout(groupBox);
    gridLayout->addWidget(boxCanvas, 0, 0, 2, 1);
    gridLayout->addWidget(updateGroupBox, 2, 0, 1, 1); //row, column, rowSpan, colSpan

    QGroupBox * groupBox = new QGroupBox(this);
    groupBox->setLayout(gridLayout);
    groupBox->setTitle("QGroupBox Grid");
    setCentralWidget(groupBox);

    QMenu *fileMenu = menuBar()->addMenu("&File");
    QMenu *showMenu = menuBar()->addMenu("&Show");

    QAction *actExit = new QAction("E&xit", fileMenu);
    QAction *actShowMsgGL = new QAction("Show Msg na Canvas", showMenu);
    QAction *actShowMsgThis = new QAction("Show Msg na MainWindow", showMenu);

    fileMenu->addAction(actExit);
    showMenu->addAction(actShowMsgGL);
    showMenu->addAction(actShowMsgThis);

    //o timer eh usado para controlar o refresh de tela, via SLOT(update()) abaixo. Ele nao faz controle de FPS
    m_timer = new QTimer(this);
    m_timer->setInterval(10);
    m_timer->start();

    //tratamento de eventos de menu, checkbox, timer, botao, slider e QSpinBox (e etc)
    connect(m_timer,        SIGNAL(timeout()),         canvas, SLOT(update()));
    connect(actExit,        SIGNAL(triggered(bool)),   this,   SLOT(close())   );
    connect(actShowMsgGL,   SIGNAL(triggered(bool)),   canvas, SLOT(showMsg()) );
    connect(actShowMsgThis, SIGNAL(triggered(bool)),   this,   SLOT(showMsg()) );
    connect(refreshRate,    SIGNAL(valueChanged(int)), this,   SLOT(updateIntervalChanged(int)) );
    connect(slider,         SIGNAL(valueChanged(int)), this,   SLOT(sliderChanged(int)) );
    connect(timerBased,     SIGNAL(clicked(bool)),     this,   SLOT(checkBoxChanged(bool)));
}

void MainWindow::checkBoxChanged(bool enabled)
{
    qDebug("Checkbox: %d", enabled );
    if (enabled) {
        m_timer->start();
    } else {
        m_timer->stop();
    }
    refreshRate->setEnabled(enabled);
}

void MainWindow::sliderChanged(int i)
{
    qDebug("Slider: %d", i );
}

void MainWindow::showMsg()
{
    QMessageBox* msg = new QMessageBox(this);
    msg->setText("Msg MainWindow\n Metodo showMsg()");
    msg->show();
}

void MainWindow::updateIntervalChanged(int value)
{
    m_timer->setInterval(value);
    if (m_timer->isActive())
        m_timer->start();
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
    qDebug("janela redimensionada ");
}
