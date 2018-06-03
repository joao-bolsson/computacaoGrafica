/**
 * Implements a Point
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 08 Apr.
 */

#include "point.h"
#include <iostream>

using namespace std;
Point::Point() {
    Point(0, 0, 0);
}

Point::Point(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;

    xcp = x;
    ycp = y;
    zcp = z;
    rotateX = 0;
    rotateY = 0;
    rotateZ = 0;
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
    return (x / (z + D)) + 100;
}

int Point::getY2d() const {
    return (y / (z + D)) + 100;
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
    xcp += x;
    ycp += y;
    zcp += z;
}

void Point::rotate(char axis) {
    // assumes that the points are already translated to the origin
    switch (axis) {
    case X:
        rotateX++;
        y = ycp*cos(ROTATE * rotateX) - zcp*sin(ROTATE * rotateX);
        z = ycp*sin(ROTATE * rotateX) + zcp*cos(ROTATE * rotateX);
        break;

    case Y:
        rotateY++;
        x = xcp*cos(ROTATE * rotateY) + zcp*sin(ROTATE * rotateY);
        z = -xcp*sin(ROTATE * rotateY) + zcp*cos(ROTATE * rotateY);
        break;

    case Z:
        rotateZ++;
        x = xcp*cos(ROTATE * rotateZ) - ycp*sin(ROTATE * rotateZ);
        y = xcp*sin(ROTATE * rotateZ) + ycp*cos(ROTATE * rotateZ);
        break;

    default:
        break;
    }
}

Point Point::copy() {
    return Point(x, y, z);
}
