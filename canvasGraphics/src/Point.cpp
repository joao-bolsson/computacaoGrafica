/**
 * Implements a Point
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 08 Apr.
 */

#include "Point.h"

Point::Point(short x, short y) {
    this->x = x;
    this->y = y;
}

short Point::getX() const {
    return x;
}

short Point::getY() const {
    return y;
}
