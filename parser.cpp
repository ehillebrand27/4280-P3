


#include <iostream>
#include "token.h"
#include "scanner.h"
#include "parser.h"
using namespace std;

token tk;

void advance() {
    tk = scanner();
}

void parserError(string expected) {
    cout << "PARSER ERROR: expected " << expected
         << " got " << tk.instance
         << " at line " << tk.line << endl;
    exit(1);
}


void parser() {
    advance();
    S();

    if (tk.id != EOFTk) {
        parserError("EOF");
    }
}


void match(tokenID expected) {
    if (tk.id == expected) {
        advance();
    } else {
        parserError("different token");
    }
}





void S() {
    cout << "Entering " << __func__ << " with token: " << tk.instance << endl;
    A();
    K();
    match(APOSTROPHE); 
}







void A() {
    cout << "Entering " << __func__ << " with token: " << tk.instance << endl;
    if (tk.id == DOLLAR || tk.id == STAR) {
        B();
    }
    else if (tk.id == MINUS) {
        C();
    }
    else if (tk.id == PERCENT || tk.id == AMPERSAND) {
        G();
        H();
        F();
        J();
        //match(APOSTROPHE);
        //S();
    }
    else {
        parserError("A");
    }
}

void B()
{
    cout << "Entering " << __func__ << " with token: " << tk.instance << endl;
    if(tk.id == DOLLAR)
    {
        match(DOLLAR);
        match(T1);
    }

    else if(tk.id == STAR)
    {
        match(STAR);
        match(T1);
    }

    else
    {
        parserError("B");
    }

}


void C()
{
    cout << "Entering " << __func__ << " with token: " << tk.instance << endl;
    if(tk.id == MINUS)
    {
        match(MINUS);
        match(T1);
        J();
    }
    else
    {
        parserError("C");
    }
}



void D()
{
    cout << "Entering " << __func__ << " with token: " << tk.instance << endl;
    if(tk.id == LPAREN || tk.id == RPAREN)
    {
        E();
        if(tk.id == T1 || tk.id == T2)
            H();
        D();
    }
}

void E()
{
    cout << "Entering " << __func__ << " with token: " << tk.instance << endl;
    if(tk.id == LPAREN)
    {
        match(LPAREN);
    }

    else if(tk.id == RPAREN)
    {
        match(RPAREN);
    }
    else 
    {
        parserError("E");
    }
}

void F()
{
    cout << "Entering " << __func__ << " with token: " << tk.instance << endl;
    if(tk.id == COMMA)
    {
        match(COMMA);
    }

    else if(tk.id == PERIOD)
    {
        match(PERIOD);
    }

    else if(tk.id == PLUS)
    {
        match(PLUS);
    }
    else 
    {
        parserError("F");
    }
}

void G()
{
    cout << "Entering " << __func__ << " with token: " << tk.instance << endl;
    if(tk.id == PERCENT)
    {
        match(PERCENT);
    }

    else if(tk.id == AMPERSAND)
    {
        match(AMPERSAND);
    }
    else 
    {
        parserError("G");
    }
}

void H()
{
    cout << "Entering " << __func__ << " with token: " << tk.instance << endl;
    if(tk.id == T1)
    {
        match(T1);
    }
    
    else if(tk.id == T2)
    {
        match(T2);
    }
    else 
    {
        parserError("H");
    }
}




void J() {
    cout << "Entering " << __func__ << " with token: " << tk.instance << endl;
    match(APOSTROPHE); // consume '
    if (tk.id == T1 || tk.id == T2) H();
    D(); 
}



void K() {
    cout << "Entering " << __func__ << " with token: " << tk.instance << endl;

    // Only parse next S if next token can start an A
    if (tk.id == DOLLAR || tk.id == STAR || tk.id == MINUS || tk.id == PERCENT || tk.id == AMPERSAND) {
        S();
        K();
    } else {
        // epsilon: sequence ends
        return;
    }
}
