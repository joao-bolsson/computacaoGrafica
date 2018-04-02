/**
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 01 Apr.
 */
#include "src/Window.h"

int main() {
    Window *window = new Window(600, 400, "Objetos");
    window->show();
    return 0;
}