/**
 * Implements a Point 3d.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 24 May.
 */
#include "point3d.h"

Point3d::Point3d() {
    Point3d(0, 0, 0);
}

Point3d::Point3d(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

int Point3d::getX() const {
    return x;
}

int Point3d::getY() const {
    return y;
}

int Point3d::getZ() const {
    return z;
}
