/**
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 25, Jun.
 */

#include <GL/glut.h>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <cmath>

#define SCREEN_X 1000
#define SCREEN_Y 600
#define SLICES 30
#define STACKS 30

using namespace std;

float rx = 0, rz = 0;

float abertura = 400.0, znear = 1, zfar = 20, aspect = 1;

// raios
float raioCamisa = 0.5, raioPistao = raioCamisa, raioBiela = 0.125, raioManivela = raioBiela;

// alturas
float alturaCamisa = 1, alturaPistao = 0.5, alturaBiela = 1.5, alturaManivela = 0.5;

// translates
float tYCamisa = 2;

float posMeio = tYCamisa - (alturaPistao / 2), posYPistao = tYCamisa;

short dir = 1, dirAngulo = -1;
bool pause = true;

float velocidade = 0.002, angulo = 0, anguloMax = 30;
float velocidadeAngulo = anguloMax / ((tYCamisa - posMeio) / velocidade);
float anguloManivela = 0, velocidadeManivela = 90 / ((tYCamisa - posMeio) / velocidade);

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
    glLoadIdentity();

    gluPerspective(abertura, aspect, znear, zfar);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    gluLookAt(0, 0, 7,  //from. Posicao onde a camera esta posicionada
              0, 0, 0,  //to. Posicao absoluta onde a camera esta vendo
              0, 1, 0); //up. Vetor Up.

    glRotatef((GLfloat) rx, 0.0f, 1.0f, 0.0f);
    glRotatef((GLfloat) rz, 1.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // camisa
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(0, tYCamisa, 0);
    glRotatef((GLfloat) 90, 1, 0, 0);
    gluCylinder(quadratic, raioCamisa, raioCamisa, alturaCamisa, SLICES, STACKS);
    glPopMatrix();

    // pistao
    glPushMatrix();
    glColor3f(0, 1, 0);
    glTranslatef(0, posYPistao, 0);
    glRotatef((GLfloat) 90, 1, 0, 0);
    gluCylinder(quadratic, raioPistao, raioPistao, alturaPistao, SLICES, STACKS);
    glPopMatrix();

    float dif = (tYCamisa - alturaPistao / 2) - posYPistao;

    // biela
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(0, tYCamisa - alturaPistao - dif, 0);
    glRotatef((GLfloat) 90, 1, 0, 0);
    glRotatef((GLfloat) angulo, 0, 1, 0);
    gluCylinder(quadratic, raioBiela, raioBiela, alturaBiela, SLICES, STACKS);
    glPopMatrix();

    // manivela
    glPushMatrix();
    glColor3f(0, 1, 1);
    glTranslatef(0, (-raioManivela * 2), 0);
    glRotatef((GLfloat) 270, 1, 0, 0);
    glRotatef((GLfloat) anguloManivela, 0, 1, 0);
    gluCylinder(quadratic, raioManivela, raioManivela, alturaManivela, SLICES, STACKS);
    glPopMatrix();

    glutSwapBuffers();

    if (!pause) {
        if (posYPistao >= tYCamisa) {
            dir = -1;
        } else if (posYPistao <= tYCamisa - (alturaCamisa / 2)) {
            dir = 1;
        }
        posYPistao += velocidade * dir;
        angulo += velocidadeAngulo * dirAngulo;
        anguloManivela -= velocidadeManivela;

        if (angulo >= anguloMax) {
            dirAngulo = -1;
        } else if (angulo <= -anguloMax) {
            dirAngulo = 1;
        }
    }
}

void changeRPM(float step) {
    velocidade += step;
    velocidadeAngulo = anguloMax / ((tYCamisa - posMeio) / velocidade);
    velocidadeManivela = 90 / ((tYCamisa - posMeio) / velocidade);
}

void keyboard(unsigned char key, int x, int y) {
    key = tolower(key);
    switch (key) {
        case 27:
            exit(0);
        case ' ':
            pause = !pause;
            break;
        case '+':
            changeRPM(0.002);
            break;
        case '-':
            changeRPM(-0.002);
            break;
        default:
            break;

    }
}

void MotionFunc(int x, int y) {
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
