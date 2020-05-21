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

StringBuilder& MapTranslate::translateString(StringBuilder& obj) {
    int amount;
    StringBuilder* arr = obj.split(' ', amount);
    StringBuilder transl;
    for (int i = 0; i < amount; i++) {
        arr[i] = (*this)[arr[i]];
        transl = transl + arr[i];
        transl = transl + ' ';
    }
    obj = transl;
    return obj;
}

MapTranslate::~MapTranslate() {

}
