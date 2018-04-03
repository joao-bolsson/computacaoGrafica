/**
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 01 Apr.
 */

#include "Window.h"

Window::Window(unsigned short width, unsigned short height, string title) {
    this->title = title;
    this->width = width;
    this->height = height;
}

void Window::show() {
    int argc = 1;
    char arg1[] = "teste";
    char *argv[] = {arg1};

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(width, height);
    glutInitWindowPosition(200, 200);
    glutCreateWindow(title.c_str());

    inicializa();

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyb);
    glutKeyboardUpFunc(keybUp);
    glutSpecialUpFunc(specialUp);
    glutSpecialFunc(special);

    glutIdleFunc(display);
    glutMouseFunc(mouseClick);
    glutPassiveMotionFunc(motion);
    glutMotionFunc(motion);
    glutMouseWheelFunc(mouseWheelCB);

    runCanvas();
}
