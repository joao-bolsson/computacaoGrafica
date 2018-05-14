/**
 * Defines a Line.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 12 May.
 */

#ifndef LINE_H
#define LINE_H

#include "shape.h"

class Line : public Shape {

protected:
    Point p1, p2;
public:

    /**
     * Default construct.
     *
     * @param p1 Start point of line.
     * @param p2 End point of line.
     */
    Line(Point p1, Point p2);

    /**
     * Sets the start point.
     * @param p1 Point to set.
     */
    void setP1(Point p1);

    /**
     * Sets the end point.
     * @param p2 Point to set.
     */
    void setP2(Point p2);

    /**
     * @return The start point of line.
     */
    Point getP1();

    /**
     * @return The end point of line.
     */
    Point getP2();

    void draw(Canvas2D *canvas);

    void drawSelectionBox(Canvas2D *canvas);

    bool isSelected(Point x);

    void translate(int x, int y);
};

#endif // LINE_H
