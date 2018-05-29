#include "solid.h"

using namespace std;

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

void Solid::rotate(char axis) {
    Point cp = c->copy();

    translate(-cp.getX(), -cp.getY(), -cp.getZ());

    // rotate all points, except the center
    for (Point *p : points) {
        p->rotate(axis);
    }

    translate(cp.getX(), cp.getX(), cp.getZ());
}
