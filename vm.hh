#ifndef VM_H
#define VM_H

#include "program.hh"
#include "value.hh"
#include <vector>
#include <iostream>
using namespace std;

class VM {
    public:
        VM();
        Program prog;
        int ip;
        vector<Value> stk;
        bool run(); // 0: success, 1: error
        Value get();
        Value peek(int i);
        void const_op();
};

#endif