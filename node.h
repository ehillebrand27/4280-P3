
#ifndef NODE_H
#define NODE_H

#include <string>
#include "token.h"
using namespace std;

struct Node {
    string label;

    token tk1;
    token tk2;

    Node* child1 = nullptr;
    Node* child2 = nullptr;
    Node* child3 = nullptr;
    Node* child4 = nullptr;
};

#endif