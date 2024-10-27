
#include "vm.hh"


#include <variant>
using namespace std;


#define BINARY_OP(op) do { \
    if (!peek(0).is_int() || !peek(1).is_int()){ \
        cerr << "Operands must be integers" << endl; \
        return 1; \
    } \
    int b = get<int>(pop().val); \
    int a = get<int>(pop().val); \
    stk.push_back(Value(a op b)); \
} while (false)

VM::VM(){
    ip = 0;
    globals.reserve(UINT8_MAX+1);
    stk.reserve(UINT8_MAX+1);
}

Value VM::pop(){
    Value v = stk.back();
    stk.pop_back();
    return v;
} 

Value VM::peek(int i){
    return stk[stk.size()-i-1];
}


bool VM::run(){
    for(ip=0;ip<prog.code.size();){
        switch(prog.code[ip++]){
            case OP_ADD: 
                BINARY_OP(+);
                break;
            case OP_SUB:
                BINARY_OP(-);
                break;
            case OP_MUL:
                BINARY_OP(*);
                break;
            case OP_DIV:
                if (get<int>(peek(0).val) == 0){
                    cerr << "Division by zero" << endl;
                    return 1;
                }
                BINARY_OP(/);
                break;
            case OP_NEG:
                if (!peek(0).is_int()){
                    cerr << "Operand must be an integer" << endl;
                    return 1;
                }
                stk.push_back(Value(-get<int>(pop().val)));
                break;
            case OP_CONST:
                stk.push_back(prog.consts[prog.code[ip++]]);
                break;
            case OP_PRINT:
                pop().print_self(); 
                cerr << endl;
                break;
            case OP_POP:
                stk.pop_back();
                break;
            case OP_SET_GLOBAL:
                globals[prog.code[ip++]] = peek(0);
                break;
            case OP_GET_GLOBAL:
                stk.push_back(globals[prog.code[ip++]]);
                break;
            default:
                cerr << "Unknown opcode " << prog.code[ip-1] << endl;
                return 1;
        }
    }
    return 0;
}