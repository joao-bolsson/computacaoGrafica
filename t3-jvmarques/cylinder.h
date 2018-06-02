/**
 * Defines a Cylinder.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 01 Jun.
 */
#ifndef CYLINDER_H
#define CYLINDER_H

#include "solid.h"
#include <vector>

using namespace std;
class Cylinder: public Solid {

private:
    int r, h, maxL, maxC;
    vector<vector<Point*>> matrix;

public:

    /**
     * Default construct.
     * @param r Cylinder radius.
     * @param h Cylinder height.
     * @param p1 Solid enter point.
     */
    Cylinder(int r, int h, Point *c);

    void draw(Canvas2D *canvas);
};

#endif // CYLINDER_H
