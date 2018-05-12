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

void Line::setP2(Point p2) {
    this->p2 = p2;
}

void Shape::draw() {
    qDebug("Draw the line");
}
