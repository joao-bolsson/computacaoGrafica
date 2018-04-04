/**
 * Show a graphic in cartesian plan.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 01 Apr.
 */
#include "src/gl_canvas2d.h"

void render() {
    // P(0,0) está no canto inferior esquerdo
    clear(1, 1, 1);
    color(0, 0, 0);

    // x rect
    rect(0, altura / 2, largura, altura / 2);
}

//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key) {
    if (key == 27) {
        exit(0);
    }
}

void keyboardUp(int key) {
//    printf("\nLiberou: %d", key);
}

void mouse(int button, int state, int x, int y) {
//    printf("\nmouse %d %d %d %d", button, state, x, y);
}

int main() {
    initCanvas(600, 400, "Plano Cartesiano");
    runCanvas();
    return 0;
}