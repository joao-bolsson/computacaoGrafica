/**
 * Trabalho 1 - Computação Gráfica - UFSM
 *
 * João Víctor Bolsson Marques - jvmarques - 201610816
 *
 * - Desenha um gráfico na tela e plota os sinais vindos da amostra.
 * - Plota os sinais com IDCT aplicada (sinais reconstruídos).
 * - Plota a diferença entre os sinais originais e os reconstruídos.
 * - Botão para carregar automaticamente o arquivo de amostras.
 * - Botão para salvar (sobrescrita) os valores reconstruídos no arquivo de entrada.
 * - Checkboxes para habilitar/desabilitar a plotagem no gráfico.
 * - Toda a interface se ajusta conforme a largura e altura da janela.
 *
 * Extra:
 * - Utiliza vetor de quantização para reconstruir os valores.
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

#define FILE_PATH "/home/joao/Downloads/samples.dct"

File *file;

vector<short> samples, dctValues, idctValues, diffValues;

// quantization matrix (line)
vector<short> vectorQuant;
short quantFactor = 2; // quantization factor

/**
 * Graphic.
 */
short areaX1 = 5, areaY1 = 60, areaX2 = 795, areaY2 = 695;

/**
 * Axis y
 */
short xRectY = 50, y1RectY = 75, y2RectY = 685;

/**
 * Axis x
 */
short x2RectX = 790, yRectX = 380;

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

/**
 * Buttons
 */
short btnY1 = 5, btnY2 = 50;
short loadX1 = 5, loadX2 = 80;
short saveX1 = 85, saveX2 = 160;

void drawButtons() {
    /**
     * Load button
     */
    color(1, 0, 0);
    rect(loadX1, btnY1, loadX2, btnY2);
    color(1, 1, 1);
    text(15, 15, "LOAD");

    /**
     * Save button
     */
    color(1, 0, 0);
    rect(saveX1, btnY1, saveX2, btnY2);
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
     * e depois transladamos para o gráfico com origem em 380.
     */
    float factorY = 1.0f;
    if (signal != 0) {
        factorY = (y2RectY - y1RectY) / 200.0f;
    }
    float y = signal * factorY + yRectX;
    auto size = static_cast<unsigned int>(samples.size());
    /**
     * O eixo X está segmentado, conforme o número de amostras.
     * Então, precisamos colocar cada amostra no seu devido lugar no gráfico
     * através do cálculo a seguir.
     */
    float seg = (x2RectX - xRectY) / (float) size;
    float x = xRectY + seg * sampleNumber;

    return Point((short) x, (short) y);
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
    areaX2 = (short) (largura - 105);
    areaY2 = (short) (altura - 5);

    color(1, 0, 0);
    rect(areaX1, areaY1, areaX2, areaY2);

    /**
     * Cartesian plan
     */
    xRectY = (short) (areaX1 + 45);
    y1RectY = (short) (areaY1 + 15);
    y2RectY = (short) (areaY2 - 10);

    x2RectX = (short) (areaX2 - 5), yRectX = (short) (((y2RectY - y1RectY) / 2) + y1RectY);

    color(1, 1, 1);
    rect(xRectY, y1RectY, xRectY, y2RectY); // y
    rect(xRectY, yRectX, x2RectX, yRectX); // x

    text(areaX1 + 15, y2RectY - 5, "100");
    text(areaX1 + 5, y1RectY - 5, "-100");
    text(areaX1 + 30, yRectX - 5, "0");

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
    // do nothing
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
        } else if (x >= loadX1 && x <= loadX2 && y >= btnY1 && y <= btnY2) {
            load();
        } else if (x >= saveX1 && x <= saveX2 && y >= btnY1 && y <= btnY2) {
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