
#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum tokenID {
    T1,         
    T2,         
    DOLLAR,     
    STAR,       
    MINUS,      
    PERCENT,    
    AMPERSAND,  
    LPAREN,     
    RPAREN,     
    COMMA,      
    PERIOD,     
    PLUS,       
    APOSTROPHE,
    EOFTk       
};

struct token {
    tokenID id;
    std::string instance;
    int line;            
};

static const std::string tokenNames[] = {
    "T1", "T2",
    "$", "*", "-", "%", "&",
    "(", ")", ",", ".", "+", "'",
    "EOFTk"
};

#endif