#include "maptranslate.h"

MapTranslate::MapTranslate() {
    size = 0;
}

void MapTranslate::add(StringBuilder& key, StringBuilder& value) {
    for (int i = 0; i < size; i++) {
        if (key == this->key[i])
            throw invalid_argument("This key already in use");
    }
    this->key.add(key);
    this->value.add(value);
    size++;
}

StringBuilder& MapTranslate::operator[] (StringBuilder& key) {
    for (int i = 0; i < size; i++) {
        if (key == this->key[i]) {
            return value[i];
        }
    }
    return key;
}

int MapTranslate::getSize() {
    return size;
}

MapTranslate& MapTranslate::operator=(MapTranslate& obj) {
    size = obj.getSize();
    key = obj.key;
    value = obj.value;
}


MapTranslate::~MapTranslate() {

}
