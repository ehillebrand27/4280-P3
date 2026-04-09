
#ifndef SCANNER_H
#define SCANNER_H

#include <fstream>
#include "token.h"

extern std::ifstream inFile;  
extern char nextChar;

token scanner();
char getNextChar();
void filter();
void skipSpaces();
void skipComments();

#endif