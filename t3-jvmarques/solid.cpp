#include "solid.h"

Solid::Solid(Point *c) {
    this->c = c;
}

void Solid::draw(Canvas2D *canvas) {
    // empty
}

vector<Point*> Solid::getPoints() {
    return points;
}

void Solid::translate(int x, int y, int z) {
    c->translate(x, y, z);

    // translate all points of the solid
    for (Point *p : points) {
        p->translate(x, y, z);
    }
}

void Solid::rotate(float x, float y, float z) {
    // TODO
}
