

#include <iostream>
#include "token.h"
#include "scanner.h"
#include "parser.h"
#include "node.h"

using namespace std;

token tk;

//get next token
void advance() {
    tk = scanner();
}

void parserError(string expected) {
    cout << "PARSER ERROR: expected " << expected
         << " got " << tk.instance
         << " at line " << tk.line << endl;
    exit(1);
}

//verifies token matches expected token type
token match(tokenID expected) {
    if (tk.id == expected) {
        token temp = tk;
        advance();
        return temp;
    } else {
        parserError("different token");
    }
}

//starts parser
Node* parser() {
    advance();
    Node* root = S();

    if (tk.id != EOFTk) {
        parserError("EOF");
    }

    return root;
}



Node* S() {
    

    Node* node = new Node();
    node->label = "S";

    node->child1 = A();
    node->child2 = K();
    node->tk1 = match(APOSTROPHE);

    return node;
}



Node* A() {
    

    Node* node = new Node();
    node->label = "A";

    if (tk.id == DOLLAR || tk.id == STAR) {
        node->child1 = B();
    }
    else if (tk.id == MINUS) {
        node->child1 = C();
    }
    else if (tk.id == PERCENT || tk.id == AMPERSAND) {
        node->child1 = G();
        node->child2 = H();
        node->child3 = F();
        node->child4 = J();
    }
    else {
        parserError("A");
    }

    return node;
}



Node* B() {
    
    Node* node = new Node();
    node->label = "B";

    if(tk.id == DOLLAR) {
        node->tk1 = match(DOLLAR);
        node->tk2 = match(T1);
    }
    else if(tk.id == STAR) {
        node->tk1 = match(STAR);
        node->tk2 = match(T1);
    }
    else {
        parserError("B");
    }

    return node;
}



Node* C() {
    

    Node* node = new Node();
    node->label = "C";

    if(tk.id == MINUS) {
        node->tk1 = match(MINUS);
        node->tk2 = match(T1);
        node->child1 = J();
    }
    else {
        parserError("C");
    }

    return node;
}



Node* D() {
    

    if(tk.id == LPAREN || tk.id == RPAREN) {
        Node* node = new Node();
        node->label = "D";

        node->child1 = E();
        node->child2 = H();
        node->child3 = D();

        return node;
    }

    return nullptr; 
}




Node* E() {
    

    Node* node = new Node();
    node->label = "E";

    if(tk.id == LPAREN) {
        node->tk1 = match(LPAREN);
    }
    else if(tk.id == RPAREN) {
        node->tk1 = match(RPAREN);
    }
    else {
        parserError("E");
    }

    return node;
}




Node* F() {
    

    Node* node = new Node();
    node->label = "F";

    if(tk.id == COMMA) {
        node->tk1 = match(COMMA);
    }
    else if(tk.id == PERIOD) {
        node->tk1 = match(PERIOD);
    }
    else if(tk.id == PLUS) {
        node->tk1 = match(PLUS);
    }
    else {
        parserError("F");
    }

    return node;
}




Node* G() {
    

    Node* node = new Node();
    node->label = "G";

    if(tk.id == PERCENT) {
        node->tk1 = match(PERCENT);
    }
    else if(tk.id == AMPERSAND) {
        node->tk1 = match(AMPERSAND);
    }
    else {
        parserError("G");
    }

    return node;
}




Node* H() {
    

    Node* node = new Node();
    node->label = "H";

    if(tk.id == T1) {
        node->tk1 = match(T1);
    }
    else if(tk.id == T2) {
        node->tk1 = match(T2);
    }
    else {
        parserError("H");
    }

    return node;
}




Node* J() {
    

    Node* node = new Node();
    node->label = "J";

    node->tk1 = match(APOSTROPHE);

    if (tk.id == T1 || tk.id == T2)
        node->child1 = H();

    node->child2 = D();

    return node;
}





Node* K() {
    

    if (tk.id == DOLLAR || tk.id == STAR || tk.id == MINUS || tk.id == PERCENT || tk.id == AMPERSAND) {
        Node* node = new Node();
        node->label = "K";

        node->child1 = S();
        node->child2 = K();

        return node;
    }

    return nullptr;
}