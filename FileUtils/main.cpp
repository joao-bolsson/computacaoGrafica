
/**
 * Simple operations (read/write) in a binary file.
 *
 * @author Joao Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 31 Mar.
 */

#include "src/File.h"

int main() {
    cout << "Hello, World!" << endl;

    cout << "Caminho completo do Arquivo: ";
    string filePath;
    cin >> filePath;

    File *file = new File(filePath);

    cout << "Vamos ler o arquivo " << filePath << endl;
    file->read();
    return 0;
}