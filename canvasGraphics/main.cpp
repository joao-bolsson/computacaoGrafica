/**
 * Show a graphic in cartesian plan.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 01 Apr.
 */
#include "src/gl_canvas2d.h"

/**
 * Initial values for width and hight of window.
 */
#define WIDTH 1000
#define HEIGHT 700
#define MARGIN_BUTTON_X 5
#define MARGIN_BUTTON_Y 5
// canvas use GLUT_BITMAP_8_BY_13 for draw text
#define FONT_H 13
#define FONT_W 8
#define PIXEL_SCALE 3

void drawButtons() {
    const char *textLoad = "LOAD";
    auto size = (short) strlen(textLoad);
    int textWidth = size * FONT_W;

    unsigned short x1 = 0, y1 = 0;
    color(1, 0, 0);
    rect(PIXEL_SCALE * (x1 + MARGIN_BUTTON_X), PIXEL_SCALE * (y1 + MARGIN_BUTTON_Y),
         PIXEL_SCALE * (x1 + textWidth), PIXEL_SCALE * (y1 + FONT_H));
    color(1, 1, 1);

    text(PIXEL_SCALE * (x1 + MARGIN_BUTTON_X), PIXEL_SCALE * (y1 + MARGIN_BUTTON_Y), textLoad);
}

void drawWindow() {
    clear(0, 0, 0); // tela com fundo preto

    drawButtons();
}

void render() {
    drawWindow();
//    // P(0,0) está no canto inferior esquerdo
//    clear(1, 1, 1);
//    color(0, 0, 0);
//
//    // x rect
//    rect(0, altura / 2, largura, altura / 2);
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
    /*
    cout << "Caminho completo do Arquivo: ";
    string filePath;
    cin >> filePath;

    File *file = new File(filePath);

    cout << "Vamos ler o arquivo " << filePath << endl;
    auto v = file->read();

    cout << "=================" << endl;

    for (auto sig : v) {
        cout << sig << endl;
    }
    cout << "=================" << endl;
    */

    initCanvas(WIDTH, HEIGHT, "Plano Cartesiano");
    runCanvas();

    return 0;
}