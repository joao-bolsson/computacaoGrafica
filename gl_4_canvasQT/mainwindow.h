/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "glCanvas2d.h"


QT_FORWARD_DECLARE_CLASS(QOpenGLWidget)

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    bool timerEnabled() const { return m_timer->isActive(); }

    QTimer   *m_timer;

};

#endif
