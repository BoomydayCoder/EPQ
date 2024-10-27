#ifndef VALUE_H
#define VALUE_H

enum ValueType {
    V_INT,
};

class Value {
    public:
        Value ();
        Value (int v);
        ValueType type;
        union {
            int v_int;
        } val;
        void print_self();
        bool is_int();
};

#endif