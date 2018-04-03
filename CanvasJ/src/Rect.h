/**
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 02 Apr.
 */

#ifndef CANVASJ_RECT_H
#define CANVASJ_RECT_H


#include "Component.h"

class Rect : public Component {
private:
    int x1, x2, y1, y2;

public:

    /**
     * Creates a rect.
     *
     * @param x1 Start x coordinate.
     * @param y1 Start y coordinate.
     * @param x2 Final x coordinate.
     * @param y2 Final y coordinate.
     */
    Rect(int x1, int y1, int x2, int y2);

    void draw() override;
};


#endif //CANVASJ_RECT_H
