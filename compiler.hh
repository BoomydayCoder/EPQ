#ifndef COMPILER_H
#define COMPILER_H

#include "exptree.hh"
#include "program.hh"

class Compiler {
    public:
        Program prog;
        void compile(ExpTree* exp);
};
#endif