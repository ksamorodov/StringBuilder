#ifndef PARSER_H
#define PARSER_H
#include "maptranslate.h"
#include <fstream>
#include <string>

using namespace std;

class Parser {
private:
MapTranslate map;

public:
    Parser(const char* path);
    MapTranslate& getMap();
};

#endif // PARSER_H
