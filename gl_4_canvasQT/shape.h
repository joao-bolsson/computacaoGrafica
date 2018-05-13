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

class Shape {

protected:
    byte r = 5, div = 10;
public:

    /**
     * Default construct
     */
    Shape();

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
};

#endif // SHAPE_H
