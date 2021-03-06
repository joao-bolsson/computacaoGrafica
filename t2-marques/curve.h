/**
 * Defines a Curve.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 13 May.
 */

#ifndef CURVE_H
#define CURVE_H

#include "shape.h"

using namespace std;

class Curve : public Shape {

private:
    vector<Point*> controlPoints;
public:

    /**
     * Creates a curve.
     */
    Curve();

    /**
     * @return The curve control points.
     */
    vector<Point*> getControlPts();

    /**
     * Adds a control point.
     * @param p Control point to add.
     */
    void addPoint(Point *p);

    /**
     * Changes a control point.
     * @param i Control point number.
     * @param x New x coordinate.
     * @param y New y coordinate
     */
    void changePoint(int i, int x, int y);

    void draw(Canvas2D *canvas);

    void drawSelectionBox(Canvas2D *canvas);

    bool isSelected(Point x);

    void translate(int x, int y);

    void rotate(bool d);

    Shape* copy();

    /**
     * @param p Selected point.
     * @return if p is  a control point - index of control point, else : -1.
     */
    int isSelectedPointCtrl(Point point);
};

#endif // CURVE_H
