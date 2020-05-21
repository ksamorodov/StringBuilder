#ifndef STRING_H
#define STRING_H
#pragma once
#include <iostream>
#include "vector.h"

using namespace std;

//Created by ksamorodov
//Last changes 19.05.20
class StringBuilder : public Vector {
private:
    void setString(std::string newStr);
    void setString(char* newStr);
public:
    StringBuilder(StringBuilder& obj);
    StringBuilder(const char* str);
    StringBuilder();

    StringBuilder& concatWith(StringBuilder& obj);

    int get(int index);

    StringBuilder& operator= (StringBuilder& obj);
    StringBuilder& operator+ (StringBuilder& obj);
    StringBuilder& operator= (std::string newStr);
    StringBuilder& operator= (char* newStr);
    StringBuilder& operator+ (char c);
    StringBuilder& toLowerCase();
    StringBuilder& toUpperCase();
    StringBuilder& firstSymbolToUpperCase();
    operator string();

    char& operator[](int index);

    bool operator== (StringBuilder& obj);
    bool operator!= (StringBuilder& obj);
    bool operator== (int length);
    bool operator!= (int length);
    bool operator>= (int length);
    bool operator<= (int length);
    bool operator> (int length);
    bool operator< (int length);

    //created by Malova Yana
    string toString();
    StringSerializable& parse(string str);

    friend istream &operator >> (istream &is, StringBuilder &obj);//
    friend ostream &operator << (ostream &os, StringBuilder &obj);
    bool startsWith(StringBuilder& obj);
    bool endsWith(StringBuilder& obj);
    int indexOf(StringBuilder& obj);

    StringBuilder* split(char cut, int& size);

    ~StringBuilder();
};


#endif // STRING_H


