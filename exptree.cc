

#include "exptree.hh"

using namespace std;

ExpTree::ExpTree(node_type t, int v){
    type = t;
    value = v;
}

ExpTree::ExpTree(node_type t, vector<ExpTree*> c){
    type = t;
    ch = move(c);
}

ExpTree::ExpTree(){
    type = INT;
    value = 0;
}

ExpTree::~ExpTree(){
    for(auto c: ch){
        delete c;
    }
}

void ExpTree::print_self(){
    switch(type){
        case ADD:
        case SUB:
        case MUL:
        case DIV:
            cerr << "(";
            ch[0]->print_self();
            cerr << " ";
            switch(type){
                case ADD:
                    cerr << "+";
                    break;
                case SUB:
                    cerr << "-";
                    break;
                case MUL:
                    cerr << "*";
                    break;
                case DIV:
                    cerr << "/";
                    break;
            }
            cerr << " ";
            ch[1]->print_self();
            cerr << ")";
            break;
        case NEG:
            cerr << "-";
            ch[0]->print_self();
            break;
        case INT:
            cerr << value;
            break;
    }
}