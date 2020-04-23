#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <string>

using namespace std;

class StringBuilder  {
private:
    char *string;
    int length;
    void setString(char* newStr);
    void setString(std::string newStr);
public:
    StringBuilder();
    StringBuilder(const char *str);
    StringBuilder(const StringBuilder &obj);

    ~StringBuilder();

    StringBuilder concatWith(StringBuilder newStr);
    int getLength();
    char charAt(int index);
    bool equals(StringBuilder secondStr);

    char* toString();

    StringBuilder operator + (const StringBuilder &obj) const;
    StringBuilder operator + (const char c) const;
    StringBuilder& operator+= (StringBuilder secondStr);
    StringBuilder &operator = (const StringBuilder &obj);
    StringBuilder& operator= (std::string newStr);
    StringBuilder& operator= (char* newStr);
    char& operator[] (int index);

    bool operator== (StringBuilder secondStr);
    bool operator== (int length);


    friend istream &operator >> (istream &is, StringBuilder &obj);
    friend ostream &operator << (ostream &os, StringBuilder &obj);

};

#endif // STRING_H


