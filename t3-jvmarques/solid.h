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
    /**
     * Solid center.
     */
    Point *c;
public:

    /**
     * Default construct.
     */
    Solid(Point *c);

    /**
     * @return The points that defines this solid.
     */
    vector<Point*> getPoints();

    /**
     * Draw the solid object.
     * @param canvas Referenced canvas.
     */
    virtual void draw(Canvas2D *canvas);

    /**
     * Translate the solid.
     * @param x Units to add to x coordinate.
     * @param y Units to add to y coordinate.
     * @param z Units to add to z coordinate.
     */
    void translate(int x, int y, int z);

    /**
     * Rotate the solid.
     * @param x Rotate factor on axis X.
     * @param y Rotate factor on axis Y.
     * @param z Rotate factor on axis Z.
     */
    void rotate(float x, float y, float z);
};

#endif // SOLID_H
