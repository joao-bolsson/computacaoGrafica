#include "shape.h"

Shape::Shape() {
    // empty
}

void Shape::draw(Canvas2D *canvas) {
    // do nothing
}

void Shape::drawSelectionBox(Canvas2D *canvas) {
    // do nothing
}

bool Shape::isSelected(Point x) {
    return false;
}

byte Shape::getId() {
    return id;
}

Point Shape::getPivo() {
    return pivo;
}

void Shape::translate(int x, int y) {
   // empty
}

void Shape::rotate(bool d) {
    // empty
}
