#include "compiler.hh"

void Compiler::compile(ExpTree* exp){
    switch(exp->type){ // Loop over types of tree node
        case ADD:
            compile(exp->ch[0]);
            compile(exp->ch[1]);
            prog.push_byte(OP_ADD);
            break;
        case SUB:
            compile(exp->ch[0]);
            compile(exp->ch[1]);
            prog.push_byte(OP_SUB);
            break;
        case MUL:
            compile(exp->ch[0]);
            compile(exp->ch[1]);
            prog.push_byte(OP_MUL);
            break;
        case DIV:
            compile(exp->ch[0]);
            compile(exp->ch[1]);
            prog.push_byte(OP_DIV);
            break;
        case NEG:
            compile(exp->ch[0]);
            prog.push_byte(OP_NEG);
            break;
        case INT:
            prog.push_const(Value(exp->num));
            break;
        case SEQ:
            for(auto c: exp->ch){
                compile(c);
            }
            break;
        case EXP:
            compile(exp->ch[0]);
            prog.push_byte(OP_POP);
            break;
        case SET:
            compile(exp->ch[1]);
            if (global_index.find(exp->ch[0]->id) == global_index.end()){
                global_index[exp->ch[0]->id] = global_index.size();
            }
            if (global_index[exp->ch[0]->id] > UINT8_MAX){
                cerr << "Too many global variables" << endl;
                exit(1);
            }
            prog.push_byte(OP_SET_GLOBAL);
            prog.push_byte(global_index[exp->ch[0]->id]);
            break;
        case ID:
            if (global_index.find(exp->id) == global_index.end()){
                cerr << "Global " << exp->id << " not found" << endl;
                exit(1);
            }
            prog.push_byte(OP_GET_GLOBAL);
            prog.push_byte(global_index[exp->id]);
            break;
        case PRINT:
            compile(exp->ch[0]);
            prog.push_byte(OP_PRINT);
            break;
    }
}