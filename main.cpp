#include <iostream>
#include "stringbuilder.h"
#include "vector.h"
#include "linkedlist.h"

using namespace std;

string vectorToString(Vector* obj) {
    string str;

    for (int i = 0; i < obj->getSize(); i++) {
        str += obj->get(i);
    }

    return str;
}

int main() {
    Vector v(10);

    for (int i = 48; i < 58; i++) {
        v[i - 48] = i;
    }
    string str = v.toString();
    Vector v2;
    v2.parse(str);
    str = " efgsdfg";
    str = v2.toString();
    cout << str;

    return 0;
}
