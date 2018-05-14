/**
 * Defines a Point.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 08 Apr.
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <QDebug>
#include "glCanvas2d.h"
#include "point.h"
#include <vector>

const byte SHAPE = 0;
const byte LINE = 1;
const byte RECTANGLE = 2;
const byte CURVE = 3;
const float ROTATE = 0.08;

class Shape {

protected:
    byte r = 5, div = 10, id;
    Point pivo;
public:

    /**
     * Default construct
     */
    Shape();

    /**
     * @return The shape identifier.
     */
    byte getId();

    /**
     * Draw the shape.
     * @param canvas Referenced canvas to draw.
     */
    virtual void draw(Canvas2D *canvas);

    /**
     * Draw the selection box of the shape.
     * @param canvas Referenced canvas.
     */
    virtual void drawSelectionBox(Canvas2D *canvas);

    /**
     * @param x Clicked point.
     * @return If the point is inside of the selection box - true, else - false.
     */
    virtual bool isSelected(Point x);

    /**
     * Translate the shape.
     * @param x Translate on axis x.
     * @param y Translate on axis y.
     */
    virtual void translate(int x, int y);

    /**
     * @return Return the pivo.
     */
    Point getPivo();

    /**
     * Rotate the shape.
     * @param d If true - rotate to the left, false - right.
     */
    virtual void rotate(bool d);
};

#endif // SHAPE_H
