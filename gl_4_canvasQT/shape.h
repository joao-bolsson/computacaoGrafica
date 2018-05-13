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
public:

    /**
     * Default construct
     */
    Shape();

    /**
     * Draw the shape
     */
    virtual void draw(Canvas2D *canvas);
};

#endif // SHAPE_H
