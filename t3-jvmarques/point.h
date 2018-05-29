/**
 * Defines a Point.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 08 Apr.
 */

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <math.h>

const short D = 100;
const char X = 'X';
const char Y = 'Y';
const char Z = 'Z';
const float ROTATE = 0.08;

class Point {
private:
    int x, y, z;

public:

    /**
     * Default point (0, 0, 0).
     */
    Point();

    /**
     * Default construct.
     *
     * @param x X coordinate.
     * @param y Y coordinate.
     * @param z Z coordinate.
     */
    Point(int x, int y, int z);

    /**
     * @return The x coordinate.
     */
    int getX() const;

    /**
     * @return The y coordinate.
     */
    int getY() const;

    /**
     * @return The x coordinate on 2d context.
     */
    int getX2d() const;

    /**
     * @return The y coordinate on 2d context.
     */
    int getY2d() const;

    /**
     * @return The z coordinate.
     */
    int getZ() const;

    /**
     * Sets new x.
     * @param x X to set.
     */
    void setX(int x);

    /**
     * Sets new y.
     * @param y Y to set.
     */
    void setY(int y);

    /**
     * Sets new z.
     * @param z Z to set.
     */
    void setZ(int z);

    /**
     * Translate the point.
     * @param x Units to add to x coordinate.
     * @param y Units to add to y coordinate.
     * @param z Units to add to z coordinate.
     */
    void translate(int x, int y, int z);

    /**
     * Rotate the point.
     * @param axis Rotate axis.
     */
    void rotate(char axis);

    /**
     * @return A copy of this point.
     */
    Point copy();
};


#endif //POINT_H
