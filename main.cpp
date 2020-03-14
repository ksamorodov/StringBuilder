#include <iostream>
#include "stringbuilder.h"
#include "string.h"

using namespace std;


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
    //labInfo();
    String fstr("Hello ");
    String sstr("World!!!");

    cout << concat(fstr, sstr).string << endl;
    cout << charAt(fstr, 1) << endl;
    cout << length(fstr) << endl;

    StringBuilder Fstr("Privet ");
    StringBuilder Sstr("Mir!!!");

    cout << Fstr.concatWith(Sstr).getString() << endl;
    cout << Fstr.charAt(1) << endl;
    cout << Fstr.getLength();

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
