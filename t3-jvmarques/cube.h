/**
 * Defines a Cube.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 20 May.
 */

#ifndef CUBE_H
#define CUBE_H

#include "solid.h"

class Cube: public Solid {

private:
    int l;
    Point *c;
public:

    /**
     * Default construct.
     * @param l Cube side size.
     * @param p1 Cube center point.
     */
    Cube(int l, Point *c);

    void draw(Canvas2D *canvas);
};

#endif // CUBE_H
