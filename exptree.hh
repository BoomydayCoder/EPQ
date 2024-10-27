#ifndef EXPTREE_H
#define EXPTREE_H

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

enum node_type {
    ADD, SUB, MUL, DIV, NEG, INT
};

class ExpTree {
    public:
        node_type type;
        int value;
        vector<ExpTree*> ch;
        ExpTree(node_type t, int v);
        ExpTree(node_type t, vector<ExpTree*> c);
        ExpTree();
        ~ExpTree();
        void print_self();
};


#endif