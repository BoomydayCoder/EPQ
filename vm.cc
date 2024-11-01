
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

void VM::print_self(){
    cerr << "ip: " << ip << endl;
    cerr << "stack: ";
    for(auto v: stk){
        v.print_self();
        cerr << " ";
    }
    cerr << endl;
}

uint16_t VM::read_short(){
    return prog.code[ip++]*(1<<8) + prog.code[ip++];
}


bool VM::run(){
    for(ip=0;ip<prog.code.size();){
        print_self();
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
            case OP_EQ:
                stk.push_back(Value(pop()==pop()));
                break;
            case OP_GRTR:
                BINARY_OP(>);
                break;
            case OP_LESS:
                BINARY_OP(<);
                break;
            case OP_NOT:
                stk.push_back(Value(!pop()));  
                break;
            case OP_CONST:
                stk.push_back(prog.consts[prog.code[ip++]]);
                break;
            case OP_PRINT:
                cerr << ">> ";
                pop().print_self(); 
                cerr << endl;
                break;
            case OP_INPUT:
                cerr << "<< " << flush;
                int v;
                cin >> v;
                stk.push_back(Value(v));
                break;
            case OP_POP:
                stk.pop_back();
                break;
            case OP_SET_GLOBAL:
                globals[prog.code[ip++]] = peek(0);
                break;
            case OP_GET_GLOBAL:
                if (globals.find(prog.code[ip]) == globals.end()){
                    cerr << "Undefined global" << endl;
                    return 1;
                } // maybe remove this to speed up language, need to do profiling
                stk.push_back(globals[prog.code[ip++]]);
                break;
            case OP_SET_LOCAL:
                stk[prog.code[ip++]] = peek(0);
                break;
            case OP_GET_LOCAL:
                stk.push_back(stk[prog.code[ip++]]);
                break;
            case OP_DEF_LOCAL:
                stk.push_back(peek(0));
                break;
            case OP_JMP_F:
                peek(0) ? read_short() : ip += read_short(); // ip += (bool(pop())-1)*read_short();  - will benchmark later
                break;
            case OP_JMP:
                ip += read_short(); 
                break;
            case OP_LOOP:
                ip += read_short(); 
                break;
            default:
                cerr << "Unknown opcode " << prog.code[ip-1] << endl;
                return 1;
        }
    }
    
    return 0;
}