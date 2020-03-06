#include "stringbuilder.h"
#include "iostream"

using namespace std;

StringBuilder::StringBuilder()
{
    length = 0;
}

StringBuilder::StringBuilder(const char* newStr) {

    length = 0;

    while (newStr[length++]);

    string = new char[length];

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

    for (int i = 0; i < getLength(); i++) {
        newString[i] = charAt(i);
    }


    for (int i = getLength(); i < secondStr.getLength() + length; i++) {
        newString[i] = secondStr.charAt(i - getLength());
    }

    StringBuilder conStr(newString);

    return conStr;
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
