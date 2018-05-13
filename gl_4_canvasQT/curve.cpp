/**
 * Implements a Curve.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 13 May.
 */

#include "curve.h"

Curve::Curve() {
    // empty
}

void Curve::addPoint(Point *p) {
    controlPoints.push_back(p);
}

void Curve::draw(Canvas2D *canvas) {
    // TODO
}

void Curve::drawSelectionBox(Canvas2D *canvas) {
    // TODO
}

bool Curve::isSelected(Point x) {
    // TODO
    return false;
}

