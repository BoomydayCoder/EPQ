#ifndef COMPILER_H
#define COMPILER_H

#include "exptree.hh"
#include "program.hh"

#include "unordered_map"
using namespace std;

class Compiler { // A class that represents the compiler as it compiles the code
    public:
        Program prog;
        void compile(ExpTree* exp);
        unordered_map<string, int> global_index;
};
#endif