#include <iostream>
#include "driver.hh"
#include "exptree.hh"
#include "program.hh"
#include "vm.hh"
#include "compiler.hh"

int main (int argc, char *argv[])
{
    driver drv;
    ExpTree* exp;
    for (++argv; argv[0]; ++argv){
        if (*argv == std::string ("-p"))
        drv.trace_parsing = true;
        else if (*argv == std::string ("-s"))
        drv.trace_scanning = true;
        else {
            bool parsed = drv.parse (*argv);
            if (!parsed) exp = drv.result;
            else return 1;
        }
    }   
    if (exp == nullptr){
        cerr << "No file passed" << endl;
        return 1;
    }
   

    exp->print_self(); cerr << endl;

    
    Compiler comp;
    comp.compile(exp);
    delete exp;
    
    comp.prog.print_self(); cerr << endl;
    
    VM vm;
    vm.prog = comp.prog;
    return vm.run();

    
    
    
}