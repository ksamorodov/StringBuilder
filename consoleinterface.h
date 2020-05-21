#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H
#include <iostream>
#include <conio.h>
#include "stringbuilder.h"
#include "dictionary.h"
#include <stdlib.h>
#include "translatefile.h"
#include <windows.h>

using namespace std;

class ConsoleInterface {
public:
    ConsoleInterface();
    void show();
};

#endif // CONSOLEINTERFACE_H
