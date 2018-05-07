#include "mainwindow.h"
//#include "ui_mainwindow.h"

MainWindow::MainWindow()
{
//    ui->setupUi(this);
    this->resize(800, 581);
    centralWidget = new QWidget(this);
    canvas = new QOpenGLWidget(centralWidget);
    canvas->setGeometry(QRect(10, 10, 781, 431));
    boxTools = new QGroupBox(centralWidget);
    boxTools->setGeometry(QRect(10, 460, 338, 61));
    gridLayout_2 = new QGridLayout(boxTools);
    gridLayout_2->setSpacing(6);
    gridLayout_2->setContentsMargins(11, 11, 11, 11);
    btnQuad = new QPushButton(boxTools);

    gridLayout_2->addWidget(btnQuad, 0, 0, 1, 1);

    btnRectangle = new QPushButton(boxTools);

    gridLayout_2->addWidget(btnRectangle, 0, 1, 1, 1);

    btnLine = new QPushButton(boxTools);

    gridLayout_2->addWidget(btnLine, 0, 2, 1, 1);

    btnCurve = new QPushButton(boxTools);

    gridLayout_2->addWidget(btnCurve, 0, 3, 1, 1);

    boxRotation = new QGroupBox(centralWidget);
    boxRotation->setGeometry(QRect(360, 460, 176, 56));
    gridLayout = new QGridLayout(boxRotation);
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    pushButton_5 = new QPushButton(boxRotation);

    gridLayout->addWidget(pushButton_5, 0, 0, 1, 1);

    pushButton_6 = new QPushButton(boxRotation);

    gridLayout->addWidget(pushButton_6, 0, 1, 1, 1);

    boxOptions = new QGroupBox(centralWidget);
    boxOptions->setGeometry(QRect(540, 460, 257, 56));
    gridLayout_3 = new QGridLayout(boxOptions);
    gridLayout_3->setSpacing(6);
    gridLayout_3->setContentsMargins(11, 11, 11, 11);
    btnClear = new QPushButton(boxOptions);

    gridLayout_3->addWidget(btnClear, 0, 0, 1, 1);

    btnOpen = new QPushButton(boxOptions);

    gridLayout_3->addWidget(btnOpen, 0, 1, 1, 1);

    btnSave = new QPushButton(boxOptions);

    gridLayout_3->addWidget(btnSave, 0, 2, 1, 1);

    this->setCentralWidget(centralWidget);
    menuBar = new QMenuBar(this);
    menuBar->setGeometry(QRect(0, 0, 800, 21));
    this->setMenuBar(menuBar);
    mainToolBar = new QToolBar(this);
    this->addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(this);
    this->setStatusBar(statusBar);

    this->setWindowTitle("Jv paint");
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
    btnSave->setText("SalvarF");
}

MainWindow::~MainWindow()
{
    qDebug("Destroy ui");
}

void MainWindow::checkBoxChanged(bool enabled)
{
    qDebug("Checkbox: %d", enabled );
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
   qDebug("update interval changed: %d", value);
}
