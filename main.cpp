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
    Vector* vec = new Vector(5);
    for (int i = 0; i < 5; i++) {
         vec->operator[](i) = i + 48;
    }

    cout << vectorToString(vec) << endl;


    StringBuilder* str = new StringBuilder("i'm string builder!");
    cout << vectorToString(str) << endl;

    vec = new StringBuilder("i'm vector and string builder");
    cout << vectorToString(vec) << endl;

    return 0;
}
