
#include "node.h"
#include <iostream>
using namespace std;


//preorder traversal 
void printTree(Node* node, int level) {

    //base case
    if (node == nullptr)
    {
        return;
    }

    //spacing
    for (int i = 0; i < level; i++)
    {
        cout << "    ";
    }

    cout << node->label;

    if (node->tk1.instance != "")
        cout << " " << node->tk1.instance;

    if (node->tk2.instance != "")
        cout << " " << node->tk2.instance;

    cout << endl;

    //left to right, increase + 1
    printTree(node->child1, level + 1);
    printTree(node->child2, level + 1);
    printTree(node->child3, level + 1);
    printTree(node->child4, level + 1);
}