#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <string>
#include "vector.h"

using namespace std;

class StringBuilder : public Vector {
private:
    void setString(char* newStr);
    void setString(std::string newStr);
public:
    StringBuilder();
    StringBuilder(const char* str);
    StringBuilder(StringBuilder& obj);
    ~StringBuilder();

    char charAt(int index);

    StringBuilder& operator= (std::string newStr);
    StringBuilder& operator= (StringBuilder& obj);
    StringBuilder& operator= (char* newStr);
    StringBuilder& operator+ (char c);
    StringBuilder& operator+ (StringBuilder& obj);

    operator string();

    char operator[](int index);

    bool operator== (int length);
    bool operator== (StringBuilder& obj);


    friend istream &operator >> (istream &is, StringBuilder &obj);//
    friend ostream &operator << (ostream &os, StringBuilder &obj);
    bool endsWith(StringBuilder& obj);
    bool startsWith(StringBuilder& obj);
    int indexOf(StringBuilder& obj);

    StringBuilder* split (char separator);
};


#endif // STRING_H


