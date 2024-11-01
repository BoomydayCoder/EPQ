#include "compiler.hh"
#include "vm.hh"

void Compiler::resolve_globals(Ast* exp){
    switch(exp->type){
        case BLK:
            break;
        case IF:
            resolve_globals(exp->ch[0]);
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

void Compiler::begin_scope(){
    scope++;
    local_counts.push_back(local_counts.back());
}

void Compiler::end_scope(){
    int to_remove = local_counts.back() - local_counts[local_counts.size()-2];
        for (int i=0; i<to_remove; ++i){
            prog.push_byte(OP_POP);
            local_index.erase(local_names.back());
            local_names.pop_back();
        }
    local_counts.pop_back();
    scope--;
}

void Compiler::compile(Ast* exp){
  
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
        case EQ:
            compile(exp->ch[0]);
            compile(exp->ch[1]);
            prog.push_byte(OP_EQ);
            break;
        case GT:
            compile(exp->ch[0]);
            compile(exp->ch[1]);
            prog.push_byte(OP_GRTR);
            break;
        case LT:
            compile(exp->ch[0]);
            compile(exp->ch[1]);
            prog.push_byte(OP_LESS);
            break;
        case GE: // not less
            compile(exp->ch[0]);
            compile(exp->ch[1]);
            prog.push_byte(OP_LESS);
            prog.push_byte(OP_NOT);
            break;
        case LE: // not greater
            compile(exp->ch[0]);
            compile(exp->ch[1]);
            prog.push_byte(OP_GRTR);
            prog.push_byte(OP_NOT);
            break;
        case NE: // not equal
            compile(exp->ch[0]);
            compile(exp->ch[1]);
            prog.push_byte(OP_EQ);
            prog.push_byte(OP_NOT);
            break;
        case NOT:
            compile(exp->ch[0]);
            prog.push_byte(OP_NOT);
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
                prog.push_byte(OP_DEF_LOCAL);
            } 
            else{
                prog.push_byte(OP_SET_LOCAL);
                prog.push_byte(local_index[exp->ch[0]->id]);
            }
            
            
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
        case BLK: {

                begin_scope();
                for(auto c: exp->ch){
                    compile(c);
                }
                end_scope();
                break;
            }
        case IF: {
            
            compile(exp->ch[0]);
            int j_else = prog.push_jump(OP_JMP_F);
            prog.push_byte(OP_POP);
            begin_scope();
            compile(exp->ch[1]);
            end_scope();
            int j_end = prog.push_jump(OP_JMP);
            prog.patch_jump(j_else);
            prog.push_byte(OP_POP);
            begin_scope();
            compile(exp->ch[2]);
            end_scope();
            prog.patch_jump(j_end);
         
            break;
        }
        case AND: {
            compile(exp->ch[0]);
            int j_end = prog.push_jump(OP_JMP_F);
            prog.push_byte(OP_POP);
            compile(exp->ch[1]);
            prog.patch_jump(j_end);
            break;
        }
        case OR: {
            compile(exp->ch[0]);
            int j_skip = prog.push_jump(OP_JMP_F);
            int j_end = prog.push_jump(OP_JMP);
            prog.patch_jump(j_skip);
            prog.push_byte(OP_POP);
            compile(exp->ch[1]);
            prog.patch_jump(j_end);
            break;
        }
        case WHL: {
            int loop_start = prog.code.size();
            compile(exp->ch[0]);
            int j_end = prog.push_jump(OP_JMP_F);
            prog.push_byte(OP_POP);
            begin_scope();
            compile(exp->ch[1]);
            end_scope();
            prog.push_loop(loop_start);
            prog.patch_jump(j_end);
            prog.push_byte(OP_POP);
            break;
        }
    }
}