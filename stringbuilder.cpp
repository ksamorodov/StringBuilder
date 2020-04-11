#include "stringbuilder.h"


using namespace std;

StringBuilder::StringBuilder(const char* newStr) {

    if (newStr == nullptr) {
        throw exception();
    }

    length = 0;

    while (newStr[length++]);

    string = new char[length];

    for (int i = 0; i < length; i++) {
        string[i] = newStr[i];
    }
}


void StringBuilder::setString(char* newStr) {
    delete[] string;
    int newLength = -1;

    while(newStr[++newLength]);

    string = new char[newLength];

    for (int i = 0; i < newLength; i++) {
        string[i] = newStr[i];
    }

    length = newLength;
    string[length] = '\0';
}

StringBuilder::StringBuilder(char* newStr) {
    if (newStr == nullptr) {
        throw exception();
    }

    length = 0;

    while (newStr[length++]);

    string = new char[length];

    for (int i = 0; i < length; i++) {
        string[i] = newStr[i];
    }
}

char* StringBuilder::toString() {
    return string;
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

    StringBuilder conStr(newString);
    delete[] newString;

    return conStr;

}

char StringBuilder::operator[] (int index) {
    return this->charAt(index);
}

void StringBuilder::operator= (StringBuilder newStr) {
    setString(newStr);
}

void StringBuilder::operator+= (StringBuilder secondStr) {
    *this = (*this).concatWith(secondStr);
}

void StringBuilder::setString(StringBuilder newStr){
    delete[] string;
    string = new char[newStr.getLength()];

    for (int i = 0; i < newStr.getLength(); i++) {
        string[i] = newStr.charAt(i);
    }

    length = newStr.getLength();
    string[length] = '\0';
}

void StringBuilder::operator= (std::string newStr){
    setString(newStr);
}

void StringBuilder::setString(std::string newStr) {
    delete[] string;
    string = new char[newStr.length()];

    for (int i = 0; i < newStr.length(); i++) {
        string[i] = newStr[i];
    }

    length = newStr.length();
    string[length] = '\0';
}

StringBuilder StringBuilder::operator+ (StringBuilder secondStr) {
   StringBuilder newStr(this->concatWith(secondStr));
   return newStr;
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

bool StringBuilder::operator== (StringBuilder secondStr) {
    return this->equals(secondStr);
}

bool StringBuilder::operator== (int length) {
    return getLength() == length;
}

bool StringBuilder::equals(StringBuilder secondStr) {
    if (getLength() == secondStr.getLength())
        for(int i = 0; i < getLength(); i++) {
            if (string[i] != secondStr[i])
                return false;
        }
    else return false;

    return true;
}


