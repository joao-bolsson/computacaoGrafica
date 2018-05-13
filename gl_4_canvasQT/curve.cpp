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
    canvas->color(1, 0, 0);
    // desenha os pontos de controle
    for (unsigned int i = 0; i < controlPoints.size(); i++) {
        Point *p = controlPoints[i];
        canvas->circleFill(p->getX(), p->getY(), 5, 10);
    }

    // desenha a curva
    for(float t = 0; t <= 1; t+= 0.001){
        double p1 = (pow(1-t, 3) * controlPoints[0]->getX()) + (3*t*pow(1-t, 2) * controlPoints[1]->getX()) + (3 * pow(t,2)* (1-t) * controlPoints[2]->getX())+ (pow(t,3) * controlPoints[3]->getX());
        double p2 = (pow(1-t, 3) * controlPoints[0]->getY()) + (3*t*pow(1-t, 2) * controlPoints[1]->getY()) + (3 * pow(t,2)* (1-t) * controlPoints[2]->getY())+ (pow(t,3) * controlPoints[3]->getY());
        canvas->point(p1, p2);
    }
}

void Curve::drawSelectionBox(Canvas2D *canvas) {
    // TODO
}

bool Curve::isSelected(Point x) {
    // TODO
    return false;
}

