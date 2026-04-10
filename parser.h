
#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include "node.h"
#include <string>

Node* parser();
void advance();
void parserError(std::string expected);

Node* S();
Node* A();
Node* B();
Node* C();
Node* D();
Node* E();
Node* F();
Node* G();
Node* H();
Node* J();
Node* K();



#endif