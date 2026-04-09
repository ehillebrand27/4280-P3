


#include <iostream>
#include "parser.h"
#include "scanner.h"

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "Usage: ./parser <inputfile>\n";
        return 1;
    }


    inFile.open(argv[1]);

    if (!inFile) {
        std::cout << "Error opening file\n";
        return 1;
    }

    nextChar = getNextChar();  // initialize scanner
    parser();
    std::cout << "Parse OK" << std::endl;
    return 0;
}