#include <iostream>
#include "stringbuilder.h"
#include "vector.h"

using namespace std;

int main() {
    StringBuilder str("Hello");
    StringBuilder str2("Helloworldkirill");

    string s = string(str);
    cout << s;
    return 0;
}
