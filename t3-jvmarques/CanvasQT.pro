QT += widgets

SOURCES += main.cpp \
           mainwindow.cpp \
           glCanvas2d.cpp \
    myCanvas.cpp \
    cube.cpp \
    solid.cpp \
    point.cpp

HEADERS += \
           mainwindow.h \
    glCanvas2d.h \
    cube.h \
    solid.h \
    point.h

target.path = $$[QT_INSTALL_EXAMPLES]/opengl/qopenglwidget

INSTALLS += target
