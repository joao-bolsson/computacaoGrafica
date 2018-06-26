/**
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 25, Jun.
 */

#include <GL/glut.h>
#include <cstdlib>
#include <cctype>
#include <cstdio>

#define SCREEN_X 500
#define SCREEN_Y 500

using namespace std;

float rx = 0, rz = 0;

float abertura = 940.0, znear = 1, zfar = 20, aspect = 1;
GLUquadricObj *quadratic;

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(abertura, aspect, znear, zfar);
    glMatrixMode(GL_MODELVIEW);

    glClearColor(0, 0, 0, 1);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glEnable(GL_DEPTH_TEST);
    quadratic = gluNewQuadric();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity( );

    gluPerspective(abertura, aspect, znear, zfar);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    gluLookAt(0, 0, 3,  //from. Posicao onde a camera esta posicionada
              0, 0, 0,  //to. Posicao absoluta onde a camera esta vendo
              0, 1, 0); //up. Vetor Up.
    glRotatef((GLfloat) rx, 0.0f, 1.0f, 0.0f);
    glRotatef((GLfloat) rz, 1.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);

    gluCylinder(quadratic, 1.0, 1, 3, 30, 30);

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    key = tolower(key);
    switch (key) {
        case 27:
            exit(0);
        case '+':
            abertura += 1;

    }
}

void MotionFunc(int x, int y) {
    float dx, dy;
    //printf("\nX = %d Y = %d", x, y);
    rx = x;
    rz = y;
}

void MouseFunc(int botao, int estado, int x, int y) {
    //printf("\n%d %d %d %d", botao, estado, x, y);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(SCREEN_X, SCREEN_Y);
    glutInitWindowPosition(450, 10);
    glutCreateWindow("Motor");

    glutDisplayFunc(display);
    glutMotionFunc(MotionFunc);
    glutMouseFunc(MouseFunc);
    glutIdleFunc(display);
    glutKeyboardFunc(keyboard);

    init();

    glutMainLoop();
    return 0;
}
