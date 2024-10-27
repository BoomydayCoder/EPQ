#include "compiler.hh"
#include "vm.hh"

void Compiler::resolve_globals(ExpTree* exp){
    switch(exp->type){
        case BLK:
            break;
        case SET:
            if(global_index.find(exp->ch[0]->id) == global_index.end()){
                global_index[exp->ch[0]->id] = global_index.size();
            }
            if (global_index[exp->ch[0]->id] > UINT8_MAX){
                cerr << "Too many global variables" << endl;
                exit(1);
            }
        default:
            for(auto c: exp->ch){
                resolve_globals(c);
            }
            break;
    }
}

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
            if (global_index.find(exp->ch[0]->id) != global_index.end()){ // it is a global, so already resolved
                prog.push_byte(OP_SET_GLOBAL);
                prog.push_byte(global_index[exp->ch[0]->id]);
                break;
            }
            // it is a local variable
            if (local_index.find(exp->ch[0]->id) == local_index.end()){
                local_index[exp->ch[0]->id] = local_counts.back()++;
                local_names.push_back(exp->ch[0]->id);
            } 
            prog.push_byte(OP_SET_LOCAL);
            prog.push_byte(local_index[exp->ch[0]->id]);
            
            break;
        case ID:
        
            if (global_index.find(exp->id) != global_index.end()){ // it is a global, so already resolved
                 prog.push_byte(OP_GET_GLOBAL);
                prog.push_byte(global_index[exp->id]);
                break;
            }
            // it is a local variable
            if (local_index.find(exp->id) == local_index.end()){
                cerr << "Undefined variable " << exp->id << endl;
                exit(1);
            }
            prog.push_byte(OP_GET_LOCAL);
            prog.push_byte(local_index[exp->id]);
            break;
           
        case PRINT:
            compile(exp->ch[0]);
            prog.push_byte(OP_PRINT);
            break;
        case INP:
            prog.push_byte(OP_INPUT);
            break;
        case BLK:

            scope++;
            local_counts.push_back(local_counts.back());

            for(auto c: exp->ch){
                compile(c);
            }
            // free all the variables in the block
            int to_remove = local_counts.back() - local_counts[local_counts.size()-2];
            for (int i=0; i<to_remove; ++i){
                prog.push_byte(OP_POP);
                local_index.erase(local_names.back());
                local_names.pop_back();
            }
            local_counts.pop_back();
            scope--;
            break;
    }
}