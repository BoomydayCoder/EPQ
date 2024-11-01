#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>
#include <cstdint>
#include "value.hh"
using namespace std;

enum op_code {
    OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_EQ, OP_LESS, OP_GRTR, OP_NOT, OP_NEG, OP_CONST, OP_PRINT, OP_INPUT, OP_POP, OP_SET_GLOBAL, OP_GET_GLOBAL, OP_SET_LOCAL, OP_GET_LOCAL, OP_DEF_LOCAL, OP_JMP_F, OP_JMP, OP_LOOP, OP_NULL,
}; // The operations of our bytecode:
// OP_ADD, OP_SUB, OP_MUL, OP_DIV: binary operations pushing and popping the stack
// OP_NEG: unary operation pushing and popping the stack
// OP_CONST: push constant from constant table to stack
// OP_PRINT: print and pop the top of the stack


class Program {
    public:
        vector<uint8_t> code;
        vector<Value> consts; // the constant table
        void push_byte(uint8_t b);
        int push_jump(uint8_t b);
        int add_const(Value v); // returns the index of the constant
        void push_const(Value v);
        void patch_short(int jmp_start);
        void print_self();
};

#endif