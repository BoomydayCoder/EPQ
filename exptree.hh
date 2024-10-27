#ifndef EXPTREE_H
#define EXPTREE_H

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

enum node_type { // Types of AST nodes
    ADD, SUB, MUL, DIV, NEG, INT, SEQ, ID, SET, EXP, PRINT, BLK, INP,
};

class ExpTree { // A class that stores the AST
    public:
        node_type type;
        int num;
        string id;
        vector<ExpTree*> ch;
        ExpTree(node_type t, int v);
        ExpTree(node_type t, string* i);
        ExpTree(node_type t, vector<ExpTree*> c);
        ExpTree(node_type t);
        ExpTree();
        ~ExpTree();
        void print_self();
        void add(ExpTree* c); // Add a child to the node
};


#endif