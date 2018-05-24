/**
 * Defines a Solid.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 20 May.
 */

#ifndef SOLID_H
#define SOLID_H

#include "glCanvas2d.h"
#include <vector>
#include "point.h"

using namespace std;
class Solid {
protected:
    vector<Point*> points;
public:

    /**
     * Default construct.
     */
    Solid();

    /**
     * @return The points that defines this solid.
     */
    vector<Point*> getPoints();

    /**
     * Draw the solid object.
     * @param canvas Referenced canvas.
     */
    virtual void draw(Canvas2D *canvas);
};

#endif // SOLID_H
