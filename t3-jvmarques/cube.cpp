#include "cube.h"

Cube::Cube(int l, Point *c) {
    this->l = l;
    this->c = c;

    // front face
    points.push_back(new Point(c->getX() - l/2, c->getY() + l/2, c->getZ() + l/2));
    points.push_back(new Point(c->getX() - l/2, c->getY() - l/2, c->getZ() + l/2));
    points.push_back(new Point(c->getX() + l/2, c->getY() - l/2, c->getZ() + l/2));
    points.push_back(new Point(c->getX() + l/2, c->getY() + l/2, c->getZ() + l/2));

    // back face
    points.push_back(new Point(c->getX() - l/2, c->getY() + l/2, c->getZ() - l/2));
    points.push_back(new Point(c->getX() - l/2, c->getY() - l/2, c->getZ() - l/2));
    points.push_back(new Point(c->getX() + l/2, c->getY() - l/2, c->getZ() - l/2));
    points.push_back(new Point(c->getX() + l/2, c->getY() + l/2, c->getZ() - l/2));
}

void Cube::draw(Canvas2D *canvas) {
    canvas->color(1, 0, 0);

    // front face
    canvas->line(points[0]->getX2d(), points[0]->getY2d(), points[1]->getX2d(), points[1]->getY2d());
    canvas->line(points[1]->getX2d(), points[1]->getY2d(), points[2]->getX2d(), points[2]->getY2d());
    canvas->line(points[2]->getX2d(), points[2]->getY2d(), points[3]->getX2d(), points[3]->getY2d());
    canvas->line(points[3]->getX2d(), points[3]->getY2d(), points[0]->getX2d(), points[0]->getY2d());

    // back face
    canvas->line(points[4]->getX2d(), points[4]->getY2d(), points[5]->getX2d(), points[5]->getY2d());
    canvas->line(points[5]->getX2d(), points[5]->getY2d(), points[6]->getX2d(), points[6]->getY2d());
    canvas->line(points[6]->getX2d(), points[6]->getY2d(), points[7]->getX2d(), points[7]->getY2d());
    canvas->line(points[7]->getX2d(), points[7]->getY2d(), points[4]->getX2d(), points[4]->getY2d());

    // creating the cube
    canvas->line(points[0]->getX2d(), points[0]->getY2d(), points[4]->getX2d(), points[4]->getY2d());
    canvas->line(points[1]->getX2d(), points[1]->getY2d(), points[5]->getX2d(), points[5]->getY2d());
    canvas->line(points[2]->getX2d(), points[2]->getY2d(), points[6]->getX2d(), points[6]->getY2d());
    canvas->line(points[3]->getX2d(), points[3]->getY2d(), points[7]->getX2d(), points[7]->getY2d());
}
