#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>
#include <cstdint>
#include "value.hh"
using namespace std;

enum op_code {
    OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_NEG, OP_CONST, OP_PRINT,
};


class Program {
    public:
        vector<uint8_t> code;
        vector<Value> consts;
        void push_byte(uint8_t b);
        int add_const(Value v); // returns the index of the constant
        void push_const(Value v);
        void print_self();
};

#endif