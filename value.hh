#ifndef VALUE_H
#define VALUE_H

#include <variant>
using namespace std;

enum ValueType {
    V_INT,
};

class Value {
    public:
        Value ();
        Value (int v);
        ValueType type;
        variant<int> val;
        void print_self();
        bool is_int();
        bool operator==(const Value& v) const;
        explicit operator bool() const;


};

#endif