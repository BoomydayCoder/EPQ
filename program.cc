#include "program.hh"

#include <iostream>
using namespace std;


void Program::push_byte(uint8_t b){
    code.push_back(b);
}

void Program::push_const(Value v){
    push_byte(OP_CONST);
    push_byte(add_const(v));
}

int Program::add_const(Value v){
    consts.push_back(v);
    return consts.size() - 1;
}

void Program::print_self(){
    for(int i=0; i<code.size();++i){
        switch(code[i]){
            case OP_ADD:
                cerr << "OP_ADD" << endl;
                break;
            case OP_SUB:
                cerr << "OP_SUB" << endl;
                break;
            case OP_MUL:
                cerr << "OP_MUL" << endl;
                break;
            case OP_DIV:
                cerr << "OP_DIV" << endl;
                break;
            case OP_NEG:
                cerr << "OP_NEG" << endl;
                break;
            case OP_CONST:
                cerr << "OP_CONST ";
                consts[code[++i]].print_self();
                cerr << endl;
                break;
            case OP_PRINT:
                cerr << "OP_PRINT" << endl;
                break;
        }
    }
}