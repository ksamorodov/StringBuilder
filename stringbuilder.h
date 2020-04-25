#ifndef STRING_H
#define STRING_H
#include "vector.h"
#include <iostream>
#include <string>

using namespace std;

template<class T>
class StringBuilder : Vector<T> {
private:
    //char* string;
    Vector<char> string;
    int length;
    void setString(char* newStr);
    void setString(std::string newStr);
public:
    StringBuilder();
    StringBuilder(const char *str);
    StringBuilder(const StringBuilder& obj);

    ~StringBuilder();

    StringBuilder concatWith(StringBuilder newStr);

    int getLength();
    char charAt(int index);
    bool equals(StringBuilder secondStr);

    vector<char> toString();

    StringBuilder operator + (const StringBuilder &obj) const;
    StringBuilder operator + (const char c) const;
    StringBuilder& operator+= (StringBuilder secondStr);
    StringBuilder& operator= (const StringBuilder &obj);
    StringBuilder& operator= (std::string newStr);
    StringBuilder& operator= (char* newStr);
    char& operator[] (int index);

    bool operator== (StringBuilder secondStr);
    bool operator== (int length);


    friend istream &operator >> (istream &is, StringBuilder &obj);
    friend ostream &operator << (ostream &os, StringBuilder &obj);

    bool endsWith(StringBuilder& obj);
    bool startsWith(StringBuilder& obj);
    int indexOf(StringBuilder& obj);

    StringBuilder* split (char separator);
};


template<class T>
StringBuilder<T>::StringBuilder()  {
    string = NULL;
    length = 0;
}

template<class T>
StringBuilder<T>::StringBuilder(const char* str)  {
    int len = -1;
    while (str[++len]);

    length = len;
    string.create(length + 1);

    for (int i = 0; str[i]; i++) {
        string[i] = str[i];
    }
}

template<class T>
StringBuilder<T> StringBuilder<T>::concatWith(StringBuilder<T> secondStr) {

    int newLength = secondStr.getLength() + length;
    char* newString = new char[newLength];

    for (int i = 0; i < secondStr.getLength() + length; i++) {
        if (i < getLength())
            newString[i] = charAt(i);
        else if (i < secondStr.getLength() + length)
            newString[i] = secondStr.charAt(i - getLength());
    }
    newString[secondStr.getLength() + length] = '\0';


    StringBuilder<T> conStr(newString);

    return conStr;

}

template<class T>
vector<char> StringBuilder<T>::toString() {
    return string;
}

template<class T>
char& StringBuilder<T>::operator[] (int index) {
    if (index >= 0)
        return string[index];
    else
        throw exception();
}

template<class T>
char StringBuilder<T>::charAt(int index) {

    if (index < 0 || index > length)
        throw exception();

    return string[index];
}

template<class T>
StringBuilder<T>::StringBuilder(const StringBuilder<T>& str)  {
    length = str.length;
    string.create(length);

    for (int i = 0; i < str.length; i++) {
        string.setElement(i, str[i]);
    }
}

template<class T>
StringBuilder<T>::~StringBuilder()  {
    string.clear();
}

template<class T>
int StringBuilder<T>::getLength()  {
    return length;
}

template<class T>
StringBuilder<T> StringBuilder<T>::operator + (const StringBuilder<T>& str) const {
    char* temp = new char[length + str.length + 1];
    for (int i = 0; charAt(i); i++) {
        temp[i] = charAt(i);
    }

    StringBuilder result(temp);
    result.concatWith(str);
    delete []temp;
    return result;
}

template<class T>
StringBuilder<T> StringBuilder<T>::operator + (const char c) const {
    int newLength;
    if(length != 0)
        newLength = this->length + 2;
    else
        newLength = 2;

    char* temp = new char[newLength];

    if(string)
        for (int i = 0; i < this->length; i++) {
            temp[i] = charAt(i);
        }

    temp[newLength - 2] = c;
    temp[newLength - 1] = '\0';

    StringBuilder result(temp);

    delete[] temp;

    return result;
}

template<class T>
StringBuilder<T>& StringBuilder<T>::operator = (const StringBuilder<T> &str) {
    if (&str == this)
        return *this;

    //delete []string;
    string.clear();

    length = str.length;
    string.create(length);

    for (int i = 0; i < length; i++) {
        string.setElement(i, str[i]);
    }
    return *this;
}

template<class T>
istream &operator >> (istream &is, StringBuilder<T>& str)  {
    int ios_size = 0;
    is.sync();
    StringBuilder<T> temp("");

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

template<class T>
ostream &operator << (ostream &os, StringBuilder<T>& str)  {
    for(int i = 0; i < str.getLength(); i++)
        os << str.string[i];
    return os;
}

template<class T>
bool StringBuilder<T>::operator== (StringBuilder<T> secondStr) {
    return this->equals(secondStr);
}

template<class T>
bool StringBuilder<T>::operator== (int length) {
    return getLength() == length;
}

template<class T>
bool StringBuilder<T>::equals(StringBuilder<T> secondStr) {
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

template<class T>
StringBuilder<T>& StringBuilder<T>::operator+= (StringBuilder<T> secondStr) {
    *this = (*this).concatWith(secondStr);

    return *this;
}

template<class T>
StringBuilder<T>& StringBuilder<T>::operator= (std::string newStr){
    setString(newStr);
    return *this;
}

template<class T>
void StringBuilder<T>::setString(std::string newStr) {
    delete[] string;
    string = new char[newStr.length()];

    for (int i = 0; i < newStr.length(); i++) {
        string[i] = newStr[i];
    }

    length = newStr.length();
}

template<class T>
void StringBuilder<T>::setString(char* newStr) {
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

template<class T>
StringBuilder<T>& StringBuilder<T>::operator= (char* newStr) {
   setString(newStr);
   return *this;
}

template<class T>
bool StringBuilder<T>::endsWith(StringBuilder<T>& obj) {
    if (obj.getLength() > length) {
        return false;
    }
    else {
        for (int i = length - obj.length; i < length; i++) {
            if (string[i] != obj.string[obj.length - length + i])
                return false;
        }
        return true;
    }
}

template<class T>
bool StringBuilder<T>::startsWith(StringBuilder<T>& obj) {
    if (obj.getLength() > length) {
        return false;
    }
    else {
        for (int i = 0; i < obj.length; i++) {
            if (string[i] != obj.string[i])
                return false;
        }
        return true;
    }
}

template<class T>
int StringBuilder<T>::indexOf(StringBuilder<T>& obj) {
    int i = -1;
    int res = 0;
    bool result;

    do {
        i++;
        result = false;

        if (string[i] == obj[0] && obj.getLength() > 1) {
            result = true;
            for (int j = 1; j < obj.length; j++) {
                if (string[i + j] != obj.string[j]) {
                    result = false;
                    break;
                }

                if (result && j == obj.length - 1) {
                    res = i;
                    break;
                }
            }
        }
        else if (string[i] == obj[0] && obj.getLength() == 1) {
            result = true;
            res = i;
        }

    } while (obj.length < length - i && result != true);

    if (result == true)
        return res;// - obj.length;
    else return length;
}

#endif // STRING_H


