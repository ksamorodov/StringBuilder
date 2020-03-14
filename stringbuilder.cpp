#include "stringbuilder.h"
#include "iostream"

using namespace std;

StringBuilder::StringBuilder(const char* newStr) {

    length = 0;

    while (newStr[length++]);

    string = new char[length]; // утечка памяти

    for (int i = 0; i < length; i++) {
        string[i] = newStr[i];
    }
}

StringBuilder::StringBuilder(const StringBuilder &newStr) {
    length = newStr.length;
    string = new char[length];

    for (int i = 0; i < length; i++) {
        string[i] = newStr.string[i];
    }
}

StringBuilder StringBuilder::concatWith(StringBuilder secondStr) {

    int newLength = secondStr.getLength() + length;
    char* newString = new char[newLength];

    for (int i = 0; i < secondStr.getLength() + length; i++) {
        if (i < getLength())
            newString[i] = charAt(i);
        else
            newString[i] = secondStr.charAt(i - getLength());
    }

    StringBuilder copyStr(newString);
    delete[] newString;


    return copyStr;
}

StringBuilder::~StringBuilder() {
    delete[] string;
}


char* StringBuilder::getString() {
    return string;
}

int StringBuilder::getLength() {
    return length - 1;
}

char StringBuilder::charAt(int index) {
    return string[index];
}

void StringBuilder::printStr() {
    cout << string;
}



