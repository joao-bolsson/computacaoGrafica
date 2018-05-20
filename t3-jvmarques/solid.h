/**
 * Defines a Solid.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 20 May.
 */

#ifndef SOLID_H
#define SOLID_H

#include "glCanvas2d.h"

class Solid {
public:

    /**
     * Default construct.
     */
    Solid();

    /**
     * Draw the solid object.
     * @param canvas Referenced canvas.
     */
    virtual void draw(Canvas2D *canvas);
};

#endif // SOLID_H
