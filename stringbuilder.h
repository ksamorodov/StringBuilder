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

    ~StringBuilder();

    char charAt(int index);

    StringBuilder& operator+ (char c);//
    StringBuilder& operator= (std::string newStr);
    StringBuilder& operator= (char* newStr);

    bool operator== (int length);


    friend istream &operator >> (istream &is, StringBuilder &obj);//
    friend ostream &operator << (ostream &os, StringBuilder &obj);
    bool endsWith(StringBuilder& obj);
    bool startsWith(StringBuilder& obj);
    int indexOf(StringBuilder& obj);

    StringBuilder* split (char separator);
};


#endif // STRING_H


