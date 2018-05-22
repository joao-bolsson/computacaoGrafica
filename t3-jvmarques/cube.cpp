#include "cube.h"

Cube::Cube(int l, Point *p1) {
    this->l = l;
    this->p1 = p1;
}

void Cube::draw(Canvas2D *canvas) {
    canvas->color(1, 0, 0);
    // front rect
    canvas->line(p1->getX(), p1->getY(), p1->getX() + l, p1->getY());
    canvas->line(p1->getX(), p1->getY(), p1->getX(), p1->getY() + l);
    canvas->line(p1->getX(), p1->getY() + l, p1->getX() + l, p1->getY() + l);
    canvas->line(p1->getX() + l, p1->getY(), p1->getX() + l, p1->getY() + l);
}
