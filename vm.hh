#ifndef VM_H
#define VM_H

#include "program.hh"
#include "value.hh"
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


class VM {
    public:
        VM();
        Program prog;
        int ip;
        vector<Value> stk;
        unordered_map<int, Value> globals; // this is an unordered map to prevent redeclarations
        bool run(); // 0: success, 1: error
        Value pop(); // Pops the value off the stack 
        Value peek(int i); // Looks at the ith top value of the stack
        void const_op();
        uint16_t read_short();
        void print_self();
};

extern VM vm;

#endif