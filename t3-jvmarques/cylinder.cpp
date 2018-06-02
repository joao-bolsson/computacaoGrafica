#include "cylinder.h"

#include <iostream>

Cylinder::Cylinder(int r, int h, Point *c):Solid(c) {
    this->r = r;
    this->h = h;

    //h precisa ser par

    this->maxL = h / 2;
    this->maxC = 12; // 2PI/(PI/6) = 30

    int startY = c->getY() - h/2;
    int endY = c->getY() + h/2;
    int stepY = h/4;

    float alfa = 0.52; // 30 * pi / 180

    for (int y = startY; y < endY; y += stepY) {
        vector<Point*> points;
        // calcula pontos da circunferencia base
        for (float factorAlfa = 0; factorAlfa < maxC; factorAlfa++) {
            Point *point = new Point(r * cos(alfa * factorAlfa), y, r * sin(alfa * factorAlfa));
            points.push_back(point);
        }
        matrix.push_back(points);
    }

}

void Cylinder::draw(Canvas2D *canvas) {
    // TODO
}
