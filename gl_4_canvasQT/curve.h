/**
 * Defines a Curve.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 13 May.
 */

#ifndef CURVE_H
#define CURVE_H

#include "shape.h"
#include <vector>

using namespace std;

class Curve : public Shape {

private:
    vector<Point*> controlPoints;
public:
    Curve();

    void addPoint(Point *p);

    void draw(Canvas2D *canvas);

    void drawSelectionBox(Canvas2D *canvas);

    bool isSelected(Point x);
};

#endif // CURVE_H
