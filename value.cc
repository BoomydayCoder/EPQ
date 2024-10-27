#include "value.hh"
#include <iostream>
using namespace std;

Value::Value(int v){
    type = V_INT;
    val.v_int = v;
}

Value::Value(){
    type = V_INT;
    val.v_int = 0;
}

void Value::print_self(){
    switch (type){
        case V_INT:
            cerr << val.v_int;
            break;
    }
}

bool Value::is_int(){
    return type == V_INT;
}