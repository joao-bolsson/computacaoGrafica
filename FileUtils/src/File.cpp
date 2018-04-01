/**
 * @author Joao Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 31 Mar.
 */

#include "File.h"

File::File(string filePath) {
    this->filePath = filePath;
}

void File::read() {
    cout << "--------------\n" << "Lendo o arquivo" << endl;
    file.open(filePath, ios::in | ios::binary);

    if (!file) exit(2);

    unsigned int size;
    file.read(reinterpret_cast<char *>(&size), sizeof(size));

    cout << "Amostras encontradas: " << size << "\n--------------" << endl;

    signed short v[size];

    file.read(reinterpret_cast<char *>(v), sizeof(v));

    for (auto i : v) cout << i << endl;

    file.close();
    cout << "--------------" << endl;
}

void File::write() {
    int v[] = {54, 43, 76, 32, 87};

    int size = sizeof(v) / sizeof(int);

    file.open(filePath, ios::out | ios::binary);

    if (!file) exit(1);

    file.write(reinterpret_cast<char *>(v), size * sizeof(int));

    file.flush();
    file.close();
}

File::~File() {
    cout << "Fim da instância do Arquivo" << endl;
}
