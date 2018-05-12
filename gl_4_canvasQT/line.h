/**
 * Defines a Line.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 12 May.
 */

#ifndef LINE_H
#define LINE_H

#include "point.h"
#include "shape.h"

class Line : public Shape {

private:
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
};

#endif // LINE_H
