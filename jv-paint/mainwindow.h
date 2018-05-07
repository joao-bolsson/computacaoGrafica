#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGridLayout>
#include <QGroupBox>
#include <QHeaderView>
#include <QMenuBar>
#include <QOpenGLWidget>
#include <QPushButton>
#include <QStatusBar>
#include <QToolBar>
#include <QWidget>
#include "glCanvas2d.h"

QT_FORWARD_DECLARE_CLASS(QOpenGLWidget)

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QWidget *centralWidget;
    QOpenGLWidget *canvas;
    QGroupBox *boxTools;
    QGridLayout *gridLayout_2;
    QPushButton *btnQuad;
    QPushButton *btnRectangle;
    QPushButton *btnLine;
    QPushButton *btnCurve;
    QGroupBox *boxRotation;
    QGridLayout *gridLayout;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QGroupBox *boxOptions;
    QGridLayout *gridLayout_3;
    QPushButton *btnClear;
    QPushButton *btnOpen;
    QPushButton *btnSave;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    MainWindow();
    ~MainWindow();

//Callbacks de Widgets
private slots:
    void updateIntervalChanged(int value);
    void showMsg();
    void sliderChanged(int i);
    void checkBoxChanged(bool b);
};

#endif // MAINWINDOW_H
