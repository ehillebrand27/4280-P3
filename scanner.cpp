#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include "token.h"
#include "scanner.h"

std::ifstream inFile;
int lineNumber = 1;
char nextChar;

// get next char from input stream
char getNextChar() {
    char ch;
    if (inFile.get(ch)) {
        if (ch == '\n') lineNumber++;
        return ch;
    }
    return EOF;
}

// skip whitespace
void skipSpaces() {
    while (isspace(nextChar)) {
        nextChar = getNextChar();
    }
}

// skip comments ! ... !
void skipComments() {
    if (nextChar == '!') {
        nextChar = getNextChar();
        while (nextChar != '!' && nextChar != EOF) {
            nextChar = getNextChar();
        }
        if (nextChar == '!') nextChar = getNextChar();
    }
}

// filter whitespace and comments
void filter() {
    while (nextChar == '!' || isspace(nextChar)) {
        if (nextChar == '!') skipComments();
        if (isspace(nextChar)) skipSpaces();
    }
}

// scanner error
void scannerError() {
    if (nextChar == '\n')
        std::cout << "SCANNER ERROR: \\n " << lineNumber << std::endl;
    else if (nextChar == EOF)
        std::cout << "SCANNER ERROR: EOF " << lineNumber << std::endl;
    else
        std::cout << "SCANNER ERROR: " << nextChar << " " << lineNumber << std::endl;
    exit(1);
}

// T1 token
token t1() {
    token tk;
    if (nextChar == '#' || nextChar == '"') {
        tk.id = T1;
        tk.instance = "";
        tk.line = lineNumber;
        tk.instance += nextChar;
        nextChar = getNextChar();

        if (!isdigit(nextChar)) scannerError();

        while (isdigit(nextChar)) {
            tk.instance += nextChar;
            nextChar = getNextChar();
        }
    }
    return tk;
}

// T2 token
token t2() {
    token tk;
    if (isalpha(nextChar)) {
        tk.id = T2;
        tk.instance = "";
        tk.line = lineNumber;
        tk.instance += nextChar;
        nextChar = getNextChar();

        while (isalpha(nextChar)) {
            tk.instance += nextChar;
            nextChar = getNextChar();
        }

        if (!isdigit(nextChar)) scannerError();

        while (isdigit(nextChar)) {
            tk.instance += nextChar;
            nextChar = getNextChar();
        }
    }
    return tk;
}

// single-char symbols with their own token IDs
token t3() {
    token tk;
    tk.instance = "";
    tk.line = lineNumber;

    switch (nextChar) {
        case '$': tk.id = DOLLAR; tk.instance = "$"; break;
        case '*': tk.id = STAR; tk.instance = "*"; break;
        case '-': tk.id = MINUS; tk.instance = "-"; break;
        case '%': tk.id = PERCENT; tk.instance = "%"; break;
        case '&': tk.id = AMPERSAND; tk.instance = "&"; break;
        case '(': tk.id = LPAREN; tk.instance = "("; break;
        case ')': tk.id = RPAREN; tk.instance = ")"; break;
        case ',': tk.id = COMMA; tk.instance = ","; break;
        case '.': tk.id = PERIOD; tk.instance = "."; break;
        case '+': tk.id = PLUS; tk.instance = "+"; break;
        case '\'': tk.id = APOSTROPHE; tk.instance = "'"; break;
        default: scannerError();
    }
    nextChar = getNextChar();
    return tk;
}

// main scanner function
token scanner() {
    filter();

    if (nextChar == '#' || nextChar == '"') return t1();
    if (isalpha(nextChar)) return t2();
    if (nextChar == '$' || nextChar == '*' || nextChar == '-' ||
        nextChar == '%' || nextChar == '&' || nextChar == '(' ||
        nextChar == ')' || nextChar == ',' || nextChar == '.' ||
        nextChar == '+' || nextChar == '\'') return t3();

    if (nextChar == EOF) {
        token tk;
        tk.id = EOFTk;
        tk.instance = "EOF";
        tk.line = lineNumber;
        return tk;
    }

    scannerError();
    token tk; // just to satisfy compiler
    return tk;
}