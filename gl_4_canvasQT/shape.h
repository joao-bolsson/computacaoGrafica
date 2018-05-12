/**
 * Defines a Point.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 08 Apr.
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <QDebug>

class Shape {
public:

    /**
     * Default construct
     */
    Shape();

    /**
     * Draw the shape
     */
    virtual void draw();
};

#endif // SHAPE_H
