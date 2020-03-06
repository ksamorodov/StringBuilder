#include <iostream>
#include "stringbuilder.h"
#include "string.h"

using namespace std;

int main() {
    StringBuilder str("hehi");
    StringBuilder str2("hihe");

    StringBuilder sdt(str.concatWith(str2));

    cout << str.getString() << "\n" << sdt.getString()
         << "\n" << &str << "\n" << &sdt;



    return 0;
}
