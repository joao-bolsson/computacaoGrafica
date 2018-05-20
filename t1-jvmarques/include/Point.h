/**
 * Defines a Point.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 08 Apr.
 */

#ifndef CANVASGRAPHICS_POINT_H
#define CANVASGRAPHICS_POINT_H

class Point {
private:
    short x, y;

public:

    /**
     * Default construct.
     * @param x X coordinate.
     * @param y Y coordinate.
     */
    Point(short x, short y);

    /**
     * @return The x coordinate.
     */
    short getX() const;

    /**
     * @return The y coordinate.
     */
    short getY() const;
};


#endif //CANVASGRAPHICS_POINT_H
