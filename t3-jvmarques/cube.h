/**
 * Defines a Cube.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 20 May.
 */

#ifndef CUBE_H
#define CUBE_H

#include "solid.h"
#include "point.h"

class Cube: public Solid {

private:
    int l;
    Point *p1;
public:

    /**
     * Default construct.
     * @param l Cube side size.
     * @param p1 First point.
     */
    Cube(int l, Point *p1);

    void draw(Canvas2D *canvas);
};

#endif // CUBE_H
