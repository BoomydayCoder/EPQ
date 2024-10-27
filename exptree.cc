

#include "exptree.hh"

using namespace std;

ExpTree::ExpTree(node_type t, int v){
    type = t;
    num = v;
    id = "";
}

ExpTree::ExpTree(node_type t, string* i){
    type = t;
    id = *i;
    num = 0;
}

ExpTree::ExpTree(node_type t, vector<ExpTree*> c){
    type = t;
    ch = move(c);
}

ExpTree::ExpTree(node_type t){
    type = t;
    num = 0;
    id = "";
}

ExpTree::ExpTree(){
    type = INT;
    num = 0;
    id = "";
}

ExpTree::~ExpTree(){
    for(auto c: ch){
        delete c;
    }
}

void ExpTree::add(ExpTree* c){
    ch.push_back(c);
}

void ExpTree::print_self(){
    switch(type){
        case SEQ:
            for(auto c: ch){
                c->print_self();
                cerr << endl;
            }
            break;
        case EXP:
            ch[0]->print_self();
            break;
        case ADD:
        case SUB:
        case MUL:
        case DIV:
        case SET:
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
                case SET:
                    cerr << ":=";
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
            cerr << num;
            break;
        case ID:
            cerr << id;
            break;
        case PRINT:
            cerr << "print ";
            ch[0]->print_self();
            break;
    }
}