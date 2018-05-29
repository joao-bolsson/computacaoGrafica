/**
 * Defines a Point.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 08 Apr.
 */

#ifndef POINT_H
#define POINT_H

const short D = 100;

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
};


#endif //POINT_H
