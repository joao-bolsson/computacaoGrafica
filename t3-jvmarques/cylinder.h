/**
 * Defines a Cylinder.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 01 Jun.
 */
#ifndef CYLINDER_H
#define CYLINDER_H

#include "solid.h"

class Cylinder: public Solid {

private:
    int d;
public:

    /**
     * Default construct.
     * @param d Cylinder diameter.
     * @param p1 Solid enter point.
     */
    Cylinder(int d, Point *c);

    void draw(Canvas2D *canvas);
};

#endif // CYLINDER_H
