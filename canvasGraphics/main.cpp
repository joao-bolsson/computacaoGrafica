/**
 * Show a graphic in cartesian plan.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 01 Apr.
 */
#include "src/gl_canvas2d.h"
#include "src/File.h"

short y_max = 100, y_min = -100;

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

    initCanvas(600, 400, "Plano Cartesiano");
    runCanvas();

    return 0;
}