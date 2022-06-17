#include <iostream>
#include "stringbuilder.h"
#include "vector.h"
//#include "linkedlist.h"
#include "maptranslate.h"
#include "parser.h"
#include <windows.h>
#include <string>
//#include <iostream>
#include "dictionary.h"
#include "consoleinterface.h"
using namespace std;

string vectorToString(Vector* obj) {
    string str;

    for (int i = 0; i < obj->getSize(); i++) {
        str += obj->get(i);
    }

    return str;
}

int main() {   
    ConsoleInterface co;
    co.show();
    return 0;
}
