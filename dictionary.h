#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "maptranslate.h"
#include "parser.h"

class Dictionary {

private:
    StringBuilder name;
    MapTranslate dict;

public:
    Dictionary(const char* path);
    StringBuilder& translateString(StringBuilder& str);
    StringBuilder& getName();
    void setName(StringBuilder& newName);
    ~Dictionary();
};

#endif // DICTIONARY_H
