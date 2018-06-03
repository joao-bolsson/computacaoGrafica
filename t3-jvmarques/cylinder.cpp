#include "cylinder.h"

#include <iostream>

using namespace std;

Cylinder::Cylinder(int r, int h, Point *c):Solid(c) {
    this->r = r;
    this->h = h;

    //h precisa ser par

    this->maxL = h / 2;
    this->maxC = 12;

    int startY = c->getY() - h/2;
    int endY = c->getY() + h/2;
    int stepY = h;

    float alfa = 0.52;

    for (int y = startY; y <= endY; y += stepY) {
        vector<Point*> points;
        // calcula pontos da circunferencia base
        for (float factorAlfa = 0.01; factorAlfa < maxC; factorAlfa++) {
            Point *point = new Point(ceil(r * cos(alfa * factorAlfa)), y, ceil(r * sin(alfa * factorAlfa)));
            points.push_back(point);

            cout << "(" << point->getX() << ", " << point->getY() << ", " << point->getZ() << ")" << " 2D: ("
                 << point->getX2d() << ", " << point->getY2d() << ")" << endl;;
        }
        matrix.push_back(points);
    }

}

void Cylinder::draw(Canvas2D *canvas) {
    canvas->color(1, 0, 0);
    int size = matrix.size();

//    cout << "size: " << size << endl;

    for (int l = 0; l < size - 1; l++) {
        auto v = matrix.at(l);
        auto v1 = matrix.at(l+1);
        for (int col = 0; col < maxC; col++) {
            auto p = v.at(col);
//            auto p1 = v.at(col+1);
            auto pp1 = v1.at(col);
//            auto pp2 = v1.at(col+1);

            cout << "l1: (" << p->getX2d() << ", " << p->getY2d() << ") L2: (" << pp1->getX2d()
                 << ", " << pp1->getY2d() << ")" << endl;

//            canvas->line(p->getX2d(), p->getY2d(), p1->getX2d(), p1->getY2d());
            canvas->line(p->getX2d(), p->getY2d(), pp1->getX2d(), pp1->getY2d());
//            canvas->line(p->getX2d(), p->getY2d(), pp2->getX2d(), pp2->getY2d());
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
