/**
 * Show a graphic in cartesian plan.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 01 Apr.
 */
#include "gl_canvas2d.h"
#include "File.h"
#include "Point.h"

/**
 * Initial values for width and hight of window.
 */
#define WIDTH 900
#define HEIGHT 700

#define X_START_RECT_Y 50 // x coordinate where the y rect of cartesian plan starts on screen
#define Y_START_RECT_Y 75 // y coordinate where the y rect of cartesian plan starts on screen
#define Y_END_RECT_Y 685 // y coordinate where the y rect of cartesian plan ends on screen (height)
#define X_END_RECT_X 790 // x coordinate where the x rect of cartesian plan ends on screen

vector<short> samples;
vector<short> dctValues;
vector<short> idctValues;
vector<short> diffValues;

// enable/disable (checkbox)
bool diffState = false;
short diffX1 = 800, diffY1 = 682, diffX2 = 815, diffY2 = 695;

bool idctState = false;
short idctX1 = 800, idctY1 = 664, idctX2 = 815, idctY2 = 677;

bool oriState = true;
short oriX1 = 800, oriY1 = 646, oriX2 = 815, oriY2 = 659;

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
    /**
     * O eixo Y é uma reta de tamanho 200, que vai de -100 até 100 (intervalo das amostras)
     * Precisamos dividir esse eixo em 200 para que ele passe a ter uma escala de 1 unidade.
     * Exemplificando, uma reta que vai do ponto (na tela) de 75 até 685, através do cálculo
     * acima, conseguimos "traduzir" ela para uma reta que vai de -100 até 100. Com o valor
     * da unidade da reta Y multiplicamos o sinal para o obter a real "escala" na tela,
     * e depois transladamos para o gráfico com origem em 380 (760*0.5).
     */
    short rectYHeight = Y_END_RECT_Y - Y_START_RECT_Y;
    short factorY = 1;
    if (signal != 0) {
        factorY = (short) (rectYHeight / 200);
    }
    auto y = signal * factorY + 760 * 0.5;
    auto size = static_cast<unsigned int>(samples.size());
    /**
     * O eixo X está segmentado, conforme o número de amostras.
     * Então, precisamos colocar cada amostra no seu devido lugar no gráfico
     * através do cálculo a seguir.
     */
    auto seg = (X_END_RECT_X - X_START_RECT_Y) / size;
    auto x = X_START_RECT_Y + seg * sampleNumber;

    return Point(x, y);
}

void applyDiff() {
    auto size = static_cast<unsigned short>(samples.size());
    for (unsigned short n = 0; n < size; n++) {
        diffValues.push_back(samples[n] - idctValues[n]);
    }
}

void applyIDCT() {
    auto size = static_cast<unsigned short>(samples.size());
    short val;
    for (unsigned short n = 0; n < size; n++) {
        double sum = 0.;
        for (short k = 0; k < size; ++k) {
            double s = (k == 0) ? sqrt(.5) : 1.;
            sum += s * dctValues[k] * cos(M_PI * (n + .5) * k / size);
        }
        val = (short) (sum * sqrt(2. / size));
        idctValues.push_back(val);
    }
}

void applyDCT() {
    auto size = static_cast<unsigned short>(samples.size());
    short val;
    for (unsigned short k = 0; k < size; k++) {
        double sum = 0.;
        double s = (k == 0) ? sqrt(.5) : 1.;
        for (int n = 0; n < size; n++) {
            sum += s * samples[n] * cos(M_PI * (n + .5) * k / size);
        }
        val = (short) (sum * sqrt(2. / size));
        dctValues.push_back(val);

        cout << k << " DCT val: " << val << endl;
    }
}

void drawDiff() {
    unsigned short i = 0;
    for (auto val : diffValues) {
        Point p = translatePoint(val, i++);

        color(0, 1, 1);
        circleFill(p.getX(), p.getY(), 2, 5);
    }
}

void drawIDCTValues() {
    unsigned short i = 0;
    for (auto val : idctValues) {
        Point p = translatePoint(val, i++);

        color(0, 0, 1);
        circleFill(p.getX(), p.getY(), 2, 5);
    }
}

void drawOriginalSamples() {
    unsigned short i = 0;
    for (auto s : samples) {
        Point p = translatePoint(s, i++);

        color(0, 1, 0);
        circleFill(p.getX(), p.getY(), 2, 5);
    }

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

    if (oriState) {
        drawOriginalSamples();
    }
    if (idctState) {
        drawIDCTValues();
    }
    if (diffState) {
        drawDiff();
    }
}

void drawCheckBox() {
    color(1, 0, 0);
    if (diffState) {
        rectFill(diffX1, diffY1, diffX2, diffY2);
    } else {
        rect(diffX1, diffY1, diffX2, diffY2);
    }
    color(1, 1, 1);
    text(820, 685, "DIF");

    color(1, 0, 0);
    if (idctState) {
        rectFill(idctX1, idctY1, idctX2, idctY2);
    } else {
        rect(idctX1, idctY1, idctX2, idctY2);
    }
    color(1, 1, 1);
    text(820, 667, "IDCT");

    color(1, 0, 0);
    if (oriState) {
        rectFill(oriX1, oriY1, oriX2, oriY2);
    } else {
        rect(oriX1, oriY1, oriX2, oriY2);
    }
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
    y = (y - altura) * -1;
    if (button == 0 && state == 0) {
        if (x >= diffX1 && x <= diffX2 && y >= diffY1 && y <= diffY2) {
            diffState = !diffState;
        } else if (x >= idctX1 && x <= idctX2 && y >= idctY1 && y <= idctY2) {
            idctState = !idctState;
        } else if (x >= oriX1 && x <= oriX2 && y >= oriY1 && y <= oriY2) {
            oriState = !oriState;
        }
    }
}

int main() {
    cout << "Caminho completo do Arquivo: ";
    string filePath = "/home/joao/Downloads/samples.dct";
//    cin >> filePath;

    File *file = new File(filePath);

    cout << "Vamos ler o arquivo " << filePath << endl;
    samples = file->read();
    applyDCT();
    applyIDCT();
    applyDiff();

    initCanvas(WIDTH, HEIGHT, "Plano Cartesiano");
    runCanvas();

    return 0;
}