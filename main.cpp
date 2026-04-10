


#include <iostream>
#include "parser.h"
#include "scanner.h"
#include "testTree.h"

using namespace std;

int main(int argc, char* argv[]) {

    //enforce correct usage
    if (argc < 2) {
        cout << "Usage: ./P3 <inputfile>\n";
        return 1;
    }

    //open the file given by user
    inFile.open(argv[1]);

    //if file does not open correctly
    if (!inFile) {
        cout << "Error opening file\n";
        return 1;
    }


    //start the scanner
    nextChar = getNextChar();  

    Node* root = parser();    

    //print the tree
    printTree(root, 0);        

    return 0;
}