
#include "vm.hh"



#define BINARY_OP(op) do { \
    if (!peek(0).is_int() || !peek(1).is_int()){ \
        cerr << "Operands must be integers" << endl; \
        return 1; \
    } \
    int b = get().val.v_int; \
    int a = get().val.v_int; \
    stk.push_back(Value(a op b)); \
} while (false)

VM::VM(){
    ip = 0;
}

Value VM::get(){
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
                if (peek(0).val.v_int == 0){
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
                stk.push_back(Value(-get().val.v_int));
                break;
            case OP_CONST:
                stk.push_back(prog.consts[prog.code[ip++]]);
                break;
            case OP_PRINT:
                stk.back().print_self();
                cerr << endl;
                break;
            default:
                cerr << "Unknown opcode " << prog.code[ip-1] << endl;
                return 1;
        }
    }
}