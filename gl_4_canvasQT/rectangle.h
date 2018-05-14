/**
 * Defines a Rectangle.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 13 May.
 */
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "line.h"

class RectangleC : public Line {

private:
    Point p3, p4;

public:

    /**
     * Default construct.
     *
     * @param p1 Point p1.
     * @param p2 Point p2.
     */
    RectangleC(Point p1, Point p2);

    void setP3(Point p3);

    void setP4(Point p4);

    Point getP3();

    Point getP4();

    void draw(Canvas2D *canvas);

    void drawSelectionBox(Canvas2D *canvas);
};

#endif // RECTANGLE_H
