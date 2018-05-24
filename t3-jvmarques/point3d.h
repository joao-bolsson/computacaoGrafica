/**
 * Defines a Point 3d.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 24 May.
 */

#ifndef POINT3D_H
#define POINT3D_H

class Point3d {
private:
    int x, y, z;
public:

    /**
     * Default 3d point (0, 0, 0).
     */
    Point3d();

    /**
     * Defines a 3d point.
     * @param x Coordinate on axis X.
     * @param y Coordinate on axis Y.
     * @param z Coordinate on axis Z.
     */
    Point3d(int x, int y, int z);

    /**
     * @return The x coordinate.
     */
    int getX() const;

    /**
     * @return The y coordinate.
     */
    int getY() const;

    /**
     * @return The z coordinate.
     */
    int getZ() const;
};

#endif // POINT3D_H
