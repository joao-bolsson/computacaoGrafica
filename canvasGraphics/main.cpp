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

void drawButtons() {
    /**
     * Load button
     */
    color(1, 0, 0);
    rect(5, 5, 80, 50);
    color(1, 1, 1);
    text(15, 15, "LOAD");

    /**
     * Save button
     */
    color(1, 0, 0);
    rect(85, 5, 160, 50);
    color(1, 1, 1);
    text(95, 15, "SAVE");
}

void drawGraphic() {
    /**
     * Graphic area
     */
    color(1, 0, 0);
    rect(5, 60, 795, 695);

    color(1, 1, 1);
    /**
     * Cartesian plan
     */
    rect(50, 75, 50, 685); // y
    // y = 685 + 75
    rect(50, (int) (760 * 0.5), 790, (int) (760 * 0.5)); // x

    text(20, 680, "100");
    text(10, 70, "-100");
    text(35, (int) (760 * 0.5) - 5, "0");
}

void drawCheckBox() {
    color(1, 0, 0);
    rectFill(800, 682, 815, 695); // enable
    color(1, 1, 1);
    text(820, 685, "DCT");

    color(1, 0, 0);
    rect(800, 664, 815, 677); // disable
    color(1, 1, 1);
    text(820, 667, "IDCT");

    color(1, 0, 0);
    rect(800, 646, 815, 659); // disable
    color(1, 1, 1);
    text(820, 649, "ORIGINAL");
}

void drawWindow() {
    clear(0, 0, 0); // tela com fundo preto

    drawButtons();
    drawGraphic();
    drawCheckBox();
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