#ifndef TRANSLATEFILE_H
#define TRANSLATEFILE_H
#include <list>
#include "dictionary.h"

using namespace std;

class TranslateFile {
//list<Dictionary> dicts;
Dictionary dict;
LinkedList text;

public:
    TranslateFile(const char* path);
    void writeTranslateInFile(const char* path);
    Dictionary& getDictionary();
};

#endif // TRANSLATEFILE_H
