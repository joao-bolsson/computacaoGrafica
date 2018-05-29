/**
 * Implements a Point
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 08 Apr.
 */

#include "point.h"
Point::Point() {
    Point(0, 0, 0);
}

Point::Point(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

int Point::getZ() const {
    return z;
}

int Point::getX2d() const {
    return x / ((z/D) + 1);
}

int Point::getY2d() const {
    return y / ((z/D) + 1);
}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}

void Point::setZ(int z) {
    this->z = z;
}

void Point::translate(int x, int y, int z) {
    this->x += x;
    this->y += y;
    this->z += z;
}

void Point::rotate(float x, float y, float z) {
    // todo
}
