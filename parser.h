
#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include <string>

void parser();
void advance();
void parserError(std::string expected);

void S();  
void A();
void B();
void C();
void D();
void E();
void F();
void G();
void H();
void J();
void K();



#endif