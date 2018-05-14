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

    /**
     * Sets the point 3.
     * @param p3 Point to set.
     */
    void setP3(Point p3);

    /**
     * Sets the point 4.
     * @param p4 Point to set.
     */
    void setP4(Point p4);

    /**
     * @return The point 3.
     */
    Point getP3();

    /**
     * @return The point 4.
     */
    Point getP4();

    void draw(Canvas2D *canvas);

    void drawSelectionBox(Canvas2D *canvas);

    void translate(int x, int y);
};

#endif // RECTANGLE_H
