#include <iostream>
#include "stringbuilder.h"
#include "string.h"

using namespace std;

std::ostream& operator << (std::ostream& os, StringBuilder str) {
    os << str.toString();
    return os;
}

std::istream& operator >> (std::istream& is, StringBuilder str) {
    char* newStr;
    is >> newStr;
    str.setString(newStr);
    return is;
}

struct String {

    String(const char* newStr) {
        length = -1;

        while (newStr[++length]);

        string = new char[length]; // утечка памяти

        for (int i = 0; i < length; i++)
            string[i] = newStr[i];
    }

    ~String() {
        delete[] string;
    }

    char* string;
    int length;
};

char charAt(String str, int index);
String concat(String firstStr, String secondStr);
int length(String str);

void labInfo();

int main() {
    StringBuilder str("hi");
    StringBuilder str2("oops");

    str += str2;
    cout << str << "\n";

    str = str + str2;
    cout << str << "\n";

    str = str2;
    cout << str << "\n";

    bool b = str == str.getLength();
    cout << b << "\n";

    cout << str[2] << "\n";

    std::string st = "i'm string";

    str = st;
    cout << str;

    return 0;
}

char charAt(String str, int index) {
    return str.string[index];
}


String concat(String firstStr, String secondStr) {
    int newLength = secondStr.length + firstStr.length - 1;
    char* newString = new char[newLength];

    for (int i = 0; i < newLength; i++)
        if (i < firstStr.length)
            newString[i] = charAt(firstStr, i);
        else
            newString[i] = charAt(secondStr, i - firstStr.length);

    String newPtrStr(newString);
    delete[] newString;

    return newPtrStr;
}

int length(String str) {
    return str.length;
}

void labInfo() {
    cout << "Лабораторная работа №1\n"
         << "По теме <<Понятие класса. Инкапсуляция>>\n"
         << "Вариант №12\n"
         << "Выполнил: Самородов Кирилл 13.03.2020\n";
}
