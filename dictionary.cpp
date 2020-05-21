#include "dictionary.h"

Dictionary::Dictionary(const char* path) {
    Parser pars(path);
    dict = pars.getMap();
}

StringBuilder& Dictionary::translateString(StringBuilder& obj) {
    int amount;
    StringBuilder* arr = obj.split(' ', amount);
    StringBuilder transl;
    for (int i = 0; i < amount; i++) {
        arr[i] = dict[arr[i]];
        transl = transl + arr[i];
        transl = transl + ' ';
    }
    obj = transl;
    return obj;
}

StringBuilder& Dictionary::getName() {
    return name;
}

void Dictionary::setName(StringBuilder& newName) {
    name = newName;
}

Dictionary::~Dictionary() {

}

