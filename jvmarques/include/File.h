/**
 * @author Joao Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 31 Mar.
 */

#ifndef FILEUTILS_FILE_H
#define FILEUTILS_FILE_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class File {

private:
    string filePath;
    fstream file;

public:
    /**
     * Default construct.
     * @param filePath The file path.
     */
    File(string filePath);

    /**
     * Reads the file
     */
    vector<signed short> read();

    /**
     * Writes a default int vector in the file (for while).
     */
    void write();
};


#endif //FILEUTILS_FILE_H
