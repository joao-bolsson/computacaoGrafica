#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "glCanvas2d.h"

QT_FORWARD_DECLARE_CLASS(QOpenGLWidget)

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

//Callbacks de Widgets
private slots:
    void updateIntervalChanged(int value);
    void showMsg();
    void sliderChanged(int i);
    void checkBoxChanged(bool b);
};

#endif // MAINWINDOW_H
