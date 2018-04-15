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

#define FILE_PATH "/home/joao/Downloads/samples.dct"

File *file;

vector<short> samples, dctValues, idctValues, diffValues;

// quantization matrix (line)
vector<short> vectorQuant;
short quantFactor = 2; // quantization factor

/**
 * Checkbox
 */
short x1 = 800, x2 = 815;

// enable/disable (checkbox)
bool diffState = false;
short diffY1 = 682, diffY2 = 695;

bool idctState = false;
short idctY1 = 664, idctY2 = 677;

bool oriState = true;
short oriY1 = 646, oriY2 = 659;

short loadX1 = 5, loadY1 = 5, loadX2 = 80, loadY2 = 50;
short saveX1 = 85, saveY1 = loadY1, saveX2 = 160, saveY2 = loadY2;

void drawButtons() {
    /**
     * Load button
     */
    color(1, 0, 0);
    rect(loadX1, loadY1, loadX2, loadY2);
    color(1, 1, 1);
    text(15, 15, "LOAD");

    /**
     * Save button
     */
    color(1, 0, 0);
    rect(saveX1, saveY1, saveX2, saveY2);
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

void buildQuantizationMatrix() {
    if (!vectorQuant.empty()) {
        return;
    }
    auto size = static_cast<unsigned short>(samples.size());
    for (unsigned short i = 0; i < size; i++) {
        // Q[i,j] = 1 + (1 + i + j) * factor
        vectorQuant.push_back((short) (1 + (1 + i) * quantFactor));
    }
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
        val = (short) (sum * sqrt(2. / size) / vectorQuant[n]);
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
    x1 = (short) (largura - 100), x2 = (short) (largura - 85);

    diffY1 = (short) (altura - 18);
    diffY2 = (short) (altura - 5);

    color(1, 0, 0);
    if (diffState) {
        rectFill(x1, diffY1, x2, diffY2);
    } else {
        rect(x1, diffY1, x2, diffY2);
    }
    color(1, 1, 1);
    text(x2 + 5, diffY1 + 3, "DIF");

    idctY1 = (short) (altura - 36);
    idctY2 = (short) (altura - 23);

    color(1, 0, 0);
    if (idctState) {
        rectFill(x1, idctY1, x2, idctY2);
    } else {
        rect(x1, idctY1, x2, idctY2);
    }
    color(1, 1, 1);
    text(x2 + 5, idctY1 + 3, "IDCT");

    oriY1 = (short) (altura - 54);
    oriY2 = (short) (altura - 41);

    color(1, 0, 0);
    if (oriState) {
        rectFill(x1, oriY1, x2, oriY2);
    } else {
        rect(x1, oriY1, x2, oriY2);
    }
    color(1, 1, 1);
    text(x2 + 5, oriY1 + 3, "ORIGINAL");
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

void reset() {
    samples.clear();
    dctValues.clear();
    idctValues.clear();
    diffValues.clear();
}

void load() {
    reset();
    cout << "Vamos ler o arquivo " << file->getFilePath() << endl;
    samples = file->read();
    buildQuantizationMatrix();
    applyDCT();
    applyIDCT();
    applyDiff();
}

void save() {
    file->write(idctValues);
}

void mouse(int button, int state, int x, int y) {
    y = (y - altura) * -1;
    if (button == 0 && state == 0) {
        if (x >= x1 && x <= x2 && y >= diffY1 && y <= diffY2) {
            diffState = !diffState;
        } else if (x >= x1 && x <= x2 && y >= idctY1 && y <= idctY2) {
            idctState = !idctState;
        } else if (x >= x1 && x <= x2 && y >= oriY1 && y <= oriY2) {
            oriState = !oriState;
        } else if (x >= loadX1 && x <= loadX2 && y >= loadY1 && y <= loadY2) {
            load();
        } else if (x >= saveX1 && x <= saveX2 && y >= saveY1 && y <= saveY2) {
            save();
        }
    }
}

int main() {
    file = new File(FILE_PATH);
    load();

    initCanvas(WIDTH, HEIGHT, "Trabalho 1 - jvmarques");
    runCanvas();

    return 0;
}