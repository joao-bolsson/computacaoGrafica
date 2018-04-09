/**
 * Show a graphic in cartesian plan.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 01 Apr.
 */
#include "src/gl_canvas2d.h"
#include "src/File.h"
#include "src/Point.h"

/**
 * Initial values for width and hight of window.
 */
#define WIDTH 900
#define HEIGHT 700

#define X_START_RECT_Y 50 // x coordinate where the y rect of cartesian plan starts on screen
#define Y_START_RECT_Y 75 // y coordinate where the y rect of cartesian plan starts on screen
#define Y_END_RECT_Y 685 // y coordinate where the y rect of cartesian plan ends on screen (height)
#define X_END_RECT_X 790 // x coordinate where the x rect of cartesian plan ends on screen

vector<signed short> samples;

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

/**
 * Transalte a point from sample to the screen.
 *
 * @param signal Y Coordinate from sample.
 * @param sampleNumber Sample number.
 */
Point translatePoint(signed short signal, int sampleNumber) {
    auto y = signal + 760 * 0.5;
    auto size = static_cast<unsigned int>(samples.size());
    auto seg = (X_END_RECT_X - X_START_RECT_Y) / size;

    auto x = sampleNumber + X_START_RECT_Y + seg * sampleNumber;

    return Point(x, y);
}

short test = 1;

void drawOriginalSamples() {
    int i = 0;
    for (auto s : samples) {
        Point p = translatePoint(s, i++);

        color(0, 1, 0);
        circleFill(p.getX(), p.getY(), 1, 5);

        // TODO: eliminar esse código
        if (test <= 32) {
            cout << test << " " << s << "= P(" << p.getX() << ", " << p.getY() << ")" << endl;
            test++;
        }
    }

    color(0, 1, 0);
    circleFill(790, 685, 5, 100);
    color(1, 1, 1);
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
    rect(X_START_RECT_Y, Y_START_RECT_Y, X_START_RECT_Y, Y_END_RECT_Y); // y
    rect(X_START_RECT_Y, (int) (760 * 0.5), X_END_RECT_X, (int) (760 * 0.5)); // x

    text(20, 680, "100");
    text(10, 70, "-100");
    text(35, (int) (760 * 0.5) - 5, "0");

    drawOriginalSamples();
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
    string filePath = "/home/joao/Downloads/samples.dct";
//    cin >> filePath;

    File *file = new File(filePath);

    cout << "Vamos ler o arquivo " << filePath << endl;
    samples = file->read();

    initCanvas(WIDTH, HEIGHT, "Plano Cartesiano");
    runCanvas();

    return 0;
}