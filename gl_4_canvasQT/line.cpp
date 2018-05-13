/**
 * Implements a Line.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 12 May.
 */
#include "line.h"

Line::Line(Point p1, Point p2) {
    this->p1 = p1;
    this->p2 = p2;
}

Point Line::getP1() {
    return p1;
}

Point Line::getP2() {
    return p2;
}

void Line::setP1(Point p1) {
    this->p1 = p1;
}

void Line::setP2(Point p2) {
    this->p2 = p2;
}

void Line::draw(Canvas2D *canvas) {
    canvas->color(1, 0, 0);
    canvas->line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
}

void Line::drawSelectionBox(Canvas2D *canvas) {
    canvas->color(1, 0, 0);
    short width = p1.getX() - p2.getX();
    short height = p1.getY() - p2.getY();

    canvas->circleFill(p1.getX(), p1.getY(), r, div);
    canvas->circleFill(p2.getX(), p2.getY(), r, div);
    canvas->circleFill(p1.getX() - width, p1.getY(), r, div);
    canvas->circleFill(p1.getX(), p1.getY() - height, r, div);
}

bool Line::isSelected(Point x) {
    if ((p1.getX() >= x.getX() && p2.getX() <= x.getX())
            || (p1.getX() <= x.getX() && p2.getX() >= x.getX())) {

        // compara os y
        if ((p1.getY() >= x.getY() && p2.getY() <= x.getY())
                || (p1.getY() <= x.getY() && p2.getY() >= x.getY())) {
            return true;
        }
    }
    return false;
}
