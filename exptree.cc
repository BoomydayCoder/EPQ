

#include "exptree.hh"

using namespace std;

Ast::Ast(node_type t, int v){
    type = t;
    num = v;
    id = "";
}

Ast::Ast(node_type t, string* i){
    type = t;
    id = *i;
    num = 0;
}

Ast::Ast(node_type t, vector<Ast*> c){
    type = t;
    ch = move(c);
}

Ast::Ast(node_type t){
    type = t;
    num = 0;
    id = "";
}

Ast::Ast(){
    type = INT;
    num = 0;
    id = "";
}

Ast::~Ast(){
    for(auto c: ch){
        delete c;
    }
}

void Ast::add(Ast* c){
    ch.push_back(c);
}

void Ast::print_self(){
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
        case EQ:
        case AND:
        case OR:
        case GT:
        case LT:
        case GE:
        case LE:
        case NE:
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
                case EQ:
                    cerr << "==";
                    break;
                case AND:
                    cerr << "&&";
                    break;
                case OR:
                    cerr << "||";
                    break;
                case GT:
                    cerr << ">";
                    break;
                case LT:
                    cerr << "<";
                    break;
                case GE:
                    cerr << ">=";
                    break;
                case LE:
                    cerr << "<=";
                    break;
                case NE:
                    cerr << "!=";
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
        case BLK:
            cerr << "{" << endl;
            ch[0]->print_self();
            cerr << "}";
            break;
        case INP:
            cerr << "input";
            break;
        case NOT:
            cerr << "!";
            ch[0]->print_self();
            break;
        case IF:
            cerr << "if ";
            ch[0]->print_self();
            cerr << " then ";
            ch[1]->print_self();
            cerr << " else ";
            ch[2]->print_self();
            break;
    }
}