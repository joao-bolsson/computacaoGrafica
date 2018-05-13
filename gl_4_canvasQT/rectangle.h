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

public:

    /**
     * Default construct.
     *
     * @param p1 Point p1.
     * @param p2 Point p2.
     */
    RectangleC(Point p1, Point p2);

    void draw(Canvas2D *canvas);

    void drawSelectionBox(Canvas2D *canvas);

    bool isSelected(Point x);
};

#endif // RECTANGLE_H
