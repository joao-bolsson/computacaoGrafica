QT += widgets

SOURCES += main.cpp \
           mainwindow.cpp \
           glCanvas2d.cpp \
    myCanvas.cpp \
    point.cpp \
    line.cpp \
    shape.cpp \
    rectangle.cpp \
    curve.cpp

HEADERS += \
           mainwindow.h \
    glCanvas2d.h \
    point.h \
    line.h \
    shape.h \
    rectangle.h \
    curve.h

target.path = $$[QT_INSTALL_EXAMPLES]/opengl/qopenglwidget

INSTALLS += target
