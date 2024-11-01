#include "program.hh"

#include <iostream>
using namespace std;


void Program::push_byte(uint8_t b){
    code.push_back(b);
}

int Program::push_jump(uint8_t b){
    int sz = code.size();
    code.push_back(b);
    code.push_back(OP_NULL);
    code.push_back(OP_NULL);
    return sz;
}

void Program::push_loop(int loop_start){
    int s = code.size() - loop_start + 3;
    if (s > UINT16_MAX){
        cerr << "Loop too far" << endl;
        exit(1);
    }
    code.push_back(OP_LOOP);
    code.push_back(OP_NULL);
    code.push_back(OP_NULL);
    push_short(s, code.size()-2);
}

void Program::push_const(Value v){
    push_byte(OP_CONST);
    push_byte(add_const(v));
}

int Program::add_const(Value v){
    consts.push_back(v);
    return consts.size() - 1;
}

void Program::push_short(uint16_t s, int loc){
    code[loc] = s >> 8;
    code[loc+1] = s & 0xFF;
}

void Program::patch_jump(int jmp_start){
    int s =  code.size() - jmp_start;
    s -= 3;
    if (s > UINT16_MAX){
        cerr << "Jump too far" << endl;
        exit(1);
    }
    push_short(s, jmp_start+1);
}

void Program::print_self(){
    
    for(int i=0; i<code.size();++i){
        // add the same spacing for each line
        cerr << i << ":\t";
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
            case OP_EQ:
                cerr << "OP_EQ" << endl;
                break;
            case OP_GRTR:
                cerr << "OP_GRTR" << endl;
                break;
            case OP_LESS:
                cerr << "OP_LESS" << endl;
                break;
            case OP_NOT:
                cerr << "OP_NOT" << endl;
                break;
            case OP_POP:
                cerr << "OP_POP" << endl;
                break;
            case OP_CONST:
                cerr << "OP_CONST ";
                consts[code[++i]].print_self();
                cerr << endl;
                break;
            case OP_PRINT:
                cerr << "OP_PRINT" << endl;
                break;
            case OP_INPUT:
                cerr << "OP_INPUT" << endl;
                break;
            case OP_SET_GLOBAL:
                cerr << "OP_SET_GLOBAL " << (int)code[++i] << endl;
                break;
            case OP_GET_GLOBAL:
                cerr << "OP_GET_GLOBAL " << (int)code[++i] << endl;
                break;
            case OP_SET_LOCAL:
                cerr << "OP_SET_LOCAL " << (int)code[++i] << endl;
                break;
            case OP_GET_LOCAL:
                cerr << "OP_GET_LOCAL " << (int)code[++i] << endl;
                break;
            case OP_DEF_LOCAL:
                cerr << "OP_DEF_LOCAL " << endl;
                break;
            case OP_JMP_F:
                cerr << "OP_JMP_F " << (int)code[++i]*(1<<8) + (int)code[++i] + 3 << endl;
                break;
            case OP_JMP:
                cerr << "OP_JMP " << (int)code[++i]*(1<<8) + (int)code[++i] + 3 << endl;
                break;
            case OP_LOOP:
                cerr << "OP_LOOP " << (int)code[++i]*(1<<8) + (int)code[++i] << endl; // needs to be changed later
                break;
        }
    }
}