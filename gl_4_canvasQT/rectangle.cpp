/**
 * Defines a Rectangle.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 13 May.
 */

#include "rectangle.h"

RectangleC::RectangleC(Point p1, Point p2):Line(p1, p2) {
    // do nothing
}

void RectangleC::draw(Canvas2D *canvas) {
    canvas->color(1, 0, 0);
    canvas->rect(p1.getX(), p1.getY(), p2.getX(), p2.getY());
}
