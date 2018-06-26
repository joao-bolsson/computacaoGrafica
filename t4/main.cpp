#include <GL/glut.h>  // GLUT, include glu.h and gl.h

#define WINDOW_WIDTH 2000
#define WINDOW_HEIGHT 600

GLUquadricObj *quadratic;

float abertura = 940.0;
float znear  = 1;
float zfar   = 20;
float aspect = 1;

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
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);

    gluCylinder(quadratic, 1.0, 1, 3, 30, 30);

    glutSwapBuffers();
}

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

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Mini Paint - 3D");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}

