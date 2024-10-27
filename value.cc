#include "value.hh"
#include <iostream>
using namespace std;

Value::Value(int v){
    type = V_INT;
    get<int>(val) = v;
}

Value::Value(){
    type = V_INT;
    get<int>(val) = 0;
}

void Value::print_self(){
    switch (type){
        case V_INT:
            cerr << get<int>(val);
            break;
    }
}

bool Value::is_int(){
    return type == V_INT;
}