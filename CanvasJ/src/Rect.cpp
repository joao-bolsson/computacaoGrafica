/**
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 02 Apr.
 */

#include "Rect.h"

Rect::Rect(int x1, int y1, int x2, int y2) {
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
}

void Rect::draw() {
    // default color: blue, for while
    color(0, 0, 1);
    rect(x1, y1, x2, y2);
}