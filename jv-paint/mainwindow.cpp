#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
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
