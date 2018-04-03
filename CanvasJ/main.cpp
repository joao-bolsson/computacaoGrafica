/**
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 01 Apr.
 */
#include "src/Window.h"
#include "src/Rect.h"

#define WIDTH 600
#define HEIGHT 400

Window *window = NULL;

void render() {
    clear(0, 0, 0);
    window->draw();
}

int main() {
    window = new Window(WIDTH, HEIGHT, "Objetos");

    // add a horizontal line
    window->addComponent(*new Rect(0, HEIGHT / 2, WIDTH, HEIGHT / 2));
    window->show();
    return 0;
}