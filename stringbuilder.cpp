#include "stringbuilder.h"

using namespace std;

StringBuilder::StringBuilder()  {
    string = NULL;
    length = 0;
}

StringBuilder::StringBuilder(const char* str)  {
    int len = -1;
    while (str[++len]);

    length = len;
    string = new char[length + 1];

    for (int i = 0; str[i]; i++) {
        string[i] = str[i];
    }
}

StringBuilder StringBuilder::concatWith(StringBuilder secondStr) {

    int newLength = secondStr.getLength() + length;
    char* newString = new char[newLength];

    for (int i = 0; i < secondStr.getLength() + length; i++) {
        if (i < getLength())
            newString[i] = charAt(i);
        else if (i < secondStr.getLength() + length)
            newString[i] = secondStr.charAt(i - getLength());
    }
    newString[secondStr.getLength() + length] = '\0';


    StringBuilder conStr(newString);

    return conStr;

}

char* StringBuilder::toString() {
    return string;
}

char& StringBuilder::operator[] (int index) {
    if (index >= 0)
        return string[index];
    else
        throw exception();
}

char StringBuilder::charAt(int index) {

    if (index < 0 || index > length)
        throw exception();

    return string[index];
}

StringBuilder::StringBuilder(const StringBuilder& str)  {
    length = str.length;
    string = new char[length];

    for (int i = 0; str.string[i]; i++) {
        string[i] = str.string[i];
    }

}

StringBuilder::~StringBuilder()  {
    delete []string;
}

int StringBuilder::getLength()  {
    return length;
}

StringBuilder StringBuilder::operator + (const StringBuilder& str) const {
    char *temp = new char[length + str.length + 1];
    for (int i = 0; this->string[i]; i++) {
        temp[i] = this->string[i];
    }

    StringBuilder result(temp);
    result.concatWith(str);
    delete []temp;
    return result;
}

StringBuilder StringBuilder::operator + (const char c) const {
    int newLength;
    if(length != 0)
        newLength = this->length + 2;
    else
        newLength = 2;

    char* temp = new char[newLength];

    if(string)
        for (int i = 0; i < this->length; i++) {
            temp[i] = this->string[i];
        }

    temp[newLength - 2] = c;
    temp[newLength - 1] = '\0';

    StringBuilder result(temp);

    delete[] temp;

    return result;
}

StringBuilder& StringBuilder::operator = (const StringBuilder &str) {
    if (&str == this)
        return *this;

    if (string != NULL)
        delete []string;

    length = str.length;
    string = new char[length];

    for (int i = 0; i < length; i++) {
        string[i] = str.string[i];
    }
    return *this;
}

istream &operator >> (istream &is, StringBuilder &str)  {
    int ios_size = 0;
    is.sync();
    StringBuilder temp("");

    while (is.peek() != 10)  {
        temp = temp + (char)is.get();
        ios_size++;
    }

    temp.string[ios_size] = '\0';

    delete[] str.string;

    str.length = temp.length;
    str.string = new char[str.length];
    str = temp;

    return is;
}

ostream &operator << (ostream &os, StringBuilder &str)  {
    for(int i = 0; i < str.getLength(); i++)
        os << str.string[i];
    return os;
}

bool StringBuilder::operator== (StringBuilder secondStr) {
    return this->equals(secondStr);
}

bool StringBuilder::operator== (int length) {
    return getLength() == length;
}

bool StringBuilder::equals(StringBuilder secondStr) {
    if (getLength() == secondStr.getLength()){
        for(int i = 0; i < getLength(); i++) {
            if (string[i] != secondStr[i])
                return false;
        }
    }
    else
        return false;

    return true;
}

StringBuilder& StringBuilder::operator+= (StringBuilder secondStr) {
    *this = (*this).concatWith(secondStr);

    return *this;
}

StringBuilder& StringBuilder::operator= (std::string newStr){
    setString(newStr);
    return *this;
}

void StringBuilder::setString(std::string newStr) {
    delete[] string;
    string = new char[newStr.length()];

    for (int i = 0; i < newStr.length(); i++) {
        string[i] = newStr[i];
    }

    length = newStr.length();
}

void StringBuilder::setString(char* newStr) {
    delete[] string;

    int newLength = -1;
    while(newStr[++newLength]);

    string = new char[newLength];

    for (int i = 0; i < newLength; i++) {
        cout << newStr[i] << endl;
        string[i] = newStr[i];
    }

    length = newLength;
}

StringBuilder& StringBuilder::operator= (char* newStr) {
   setString(newStr);
   return *this;
}
