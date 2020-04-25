#include <iostream>
#include "stringbuilder.h"
#include "vector.h"


using namespace std;


int main() {
    StringBuilder<char> a("hi");
    StringBuilder<char> b(" World!!");
    a += b;
    for (int i = 0; i < a.getLength(); i++) {
        cout << a[i];
    }

    return 0;
}
