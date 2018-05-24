#include "cube.h"

Cube::Cube(int l, Point *p) {
    this->l = l;
    this->p1 = p;


    // vertices definidos em sentido horário a partir do ponto p
    // para as duas faces

    // defines the points of cube
    points.push_back(p1);
    points.push_back(new Point(p1->getX(), p1->getY() + l));
    points.push_back(new Point(p1->getX() + l, p1->getY() + l));
    points.push_back(new Point(p1->getX() + l, p1->getY()));

    points.push_back(new Point(p1->getX() + (l/2), p1->getY() + (l/2)));
    points.push_back(new Point(p1->getX() + (l/2), p1->getY() + l + (l/2)));
    points.push_back(new Point(p1->getX() + l + (l/2), p1->getY() + l + (l/2)));
    points.push_back(new Point(p1->getX() + l + (l/2), p1->getY() + (l/2)));
}

void Cube::draw(Canvas2D *canvas) {
    canvas->color(1, 0, 0);

    // front face
    canvas->line(points[0]->getX(), points[0]->getY(), points[1]->getX(), points[1]->getY());
    canvas->line(points[1]->getX(), points[1]->getY(), points[2]->getX(), points[2]->getY());
    canvas->line(points[2]->getX(), points[2]->getY(), points[3]->getX(), points[3]->getY());
    canvas->line(points[3]->getX(), points[3]->getY(), points[0]->getX(), points[0]->getY());

    // back face
    canvas->line(points[4]->getX(), points[4]->getY(), points[5]->getX(), points[5]->getY());
    canvas->line(points[5]->getX(), points[5]->getY(), points[6]->getX(), points[6]->getY());
    canvas->line(points[6]->getX(), points[6]->getY(), points[7]->getX(), points[7]->getY());
    canvas->line(points[7]->getX(), points[7]->getY(), points[4]->getX(), points[4]->getY());

    // creating the cube
    canvas->line(points[0]->getX(), points[0]->getY(), points[4]->getX(), points[4]->getY());
    canvas->line(points[1]->getX(), points[1]->getY(), points[5]->getX(), points[5]->getY());
    canvas->line(points[2]->getX(), points[2]->getY(), points[6]->getX(), points[6]->getY());
    canvas->line(points[3]->getX(), points[3]->getY(), points[7]->getX(), points[7]->getY());
}
