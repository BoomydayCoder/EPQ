#include "value.hh"
#include <iostream>
using namespace std;

Value::Value(int v){
    type = V_INT;
    get<int>(val) = v;
}

Value::Value(bool v){
    type = V_INT;
    get<int>(val) = (v ? 1 : 0);
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

bool Value::operator==(const Value& v) const{
    if (type != v.type){
        return false;
    }
    switch(type){
        case V_INT:
            return get<int>(val) == get<int>(v.val);
    }
    return false;
}

Value::operator bool() const{
    switch(type){
        case V_INT:
            return get<int>(val) != 0;
    }
    return false;
}