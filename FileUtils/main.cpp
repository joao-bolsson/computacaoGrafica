
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

    cout << "Quantidade de linhas a serem lidas: ";
    int size;
    cin >> size;

    File *file = new File(filePath);

    cout << "Vamos ler " << size << " linhas do arquivo " << filePath << endl;
    file->read(size);
    return 0;
}