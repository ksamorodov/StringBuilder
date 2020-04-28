#include <iostream>
#include "stringbuilder.h"
#include "vector.h"

using namespace std;

string vectorToString(Vector& obj) {
    string str;
    for (int i = 0; i < obj.getSize(); i++) {
        str += char(obj[i]);
    }
    return str;
}

int main() {

    return 0;
}
