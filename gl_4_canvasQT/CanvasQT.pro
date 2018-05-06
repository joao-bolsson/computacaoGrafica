QT += widgets

SOURCES += main.cpp \
           mainwindow.cpp \
           glCanvas2d.cpp \
    myCanvas.cpp

HEADERS += \
           mainwindow.h \
    glCanvas2d.h

target.path = $$[QT_INSTALL_EXAMPLES]/opengl/qopenglwidget

INSTALLS += target
