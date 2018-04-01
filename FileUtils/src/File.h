/**
 * @author Joao Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 31 Mar.
 */

#ifndef FILEUTILS_FILE_H
#define FILEUTILS_FILE_H

#include <iostream>
#include <fstream>

using namespace std;

class File {
    string filePath;
    fstream file;

public:
    /**
     * Default construct.
     * @param filePath The file path.
     */
    File(string filePath);

    /**
     * Object destructor.
     */
    ~File();

    /**
     * Reads the file
     * @param size Stream size.
     */
    void read(int size);

    /**
     * Writes a default int vector in the file (for while).
     */
    void write();
};


#endif //FILEUTILS_FILE_H
