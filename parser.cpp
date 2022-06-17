#include "parser.h"

Parser::Parser(const char* path) {
    ifstream fin(path);
    if (!fin.is_open()) {
        throw invalid_argument("File can't be opened in parse");
    }

    string k;
    string v;
    StringBuilder key;
    StringBuilder value;
//    getline(fin, k);
    while(getline(fin, k) && getline(fin, v)) {
        key = k;
        value = v;
        map.add(key, value);
    }

    fin.close();
}

MapTranslate& Parser::getMap() {
    return map;
}
