#ifndef MAPTRANSLATE_H
#define MAPTRANSLATE_H
#include "linkedlist.h"

class MapTranslate {
private:
int size;
LinkedList key;
LinkedList value;
public:
    MapTranslate();
    void add(StringBuilder& key, StringBuilder& value);
    StringBuilder& operator[] (StringBuilder& key);
    int getSize();
    MapTranslate& operator=(MapTranslate& obj);
    ~MapTranslate();
};

#endif // MAPTRANSLATE_H
