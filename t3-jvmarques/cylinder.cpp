#include "cylinder.h"

Cylinder::Cylinder(int r, int h, Point *c):Solid(c) {
    this->r = r;
    this->h = h;

}

void Cylinder::draw(Canvas2D *canvas) {
    // TODO
}
