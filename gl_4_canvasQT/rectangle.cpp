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

void RectangleC::drawSelectionBox(Canvas2D *canvas) {
    canvas->color(1, 0, 0);
    short width = p1.getX() - p2.getX();
    short height = p1.getY() - p2.getY();

    byte r = 5, div = 10;

    canvas->circleFill(p1.getX(), p1.getY(), r, div);
    canvas->circleFill(p2.getX(), p2.getY(), r, div);
    canvas->circleFill(p1.getX() - width, p1.getY(), r, div);
    canvas->circleFill(p1.getX(), p1.getY() - height, r, div);
}

bool RectangleC::isSelected(Point x) {
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
