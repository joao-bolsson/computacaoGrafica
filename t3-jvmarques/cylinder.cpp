#include "cylinder.h"

#include <iostream>

using namespace std;

Cylinder::Cylinder(int r, int h, Point *c):Solid(c) {
    this->r = r;
    this->h = h;

    float x, y, z;
    float step = 0.628;
    maxL = 0;
    maxC = 0;

    for (float t = 0.0; t <= 6.28; t +=step) {
        vector<Point*> pointsM;
        cout << " linha " << maxL << endl;
        for (float a = 0; a <= 3.14; a +=step) {
            x = r * cos(a) + c->getX();
            y = r * sin(a) + c->getY();
            z = t + c->getZ();
            Point *p = new Point(x, y, z);

            pointsM.push_back(p);
            if (maxL == 0) {
                maxC++; // o numero de colunas nao se altera na matriz
            }
        }
        matrix.push_back(pointsM);
        maxL++;
    }
}

void Cylinder::draw(Canvas2D *canvas) {
    canvas->color(1, 0, 0);

    for (int l = 0; l < maxL - 1; l++) {
        auto v = matrix.at(l);
        auto v1 = matrix.at(l + 1);

        for (int col = 0; col < maxC - 1; col++) {
            auto p = v.at(col);
            auto p1 = v.at(col + 1);
            auto pp1 = v1.at(col);
            auto pp2 = v1.at(col + 1);

            canvas->line(p->getX2d(), p->getY2d(), p1->getX2d(), p1->getY2d());
            canvas->line(p->getX2d(), p->getY2d(), pp1->getX2d(), pp1->getY2d());
            canvas->line(p->getX2d(), p->getY2d(), pp2->getX2d(), pp2->getY2d());
        }
    }
}

void Cylinder::translate(int x, int y, int z) {
    c->translate(x, y, z);

    for (auto v : matrix) {
        for (auto p : v) {
            p->translate(x, y, z);
        }
    }
}

void Cylinder::rotate(char axis) {
    Point cp = c->copy();

    translate(-cp.getX(), -cp.getY(), -cp.getZ());

    for (auto v : matrix) {
        for (auto p : v) {
            p->rotate(axis);
        }
    }

    translate(cp.getX(), cp.getX(), cp.getZ());
}
