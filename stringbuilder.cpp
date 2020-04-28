#include "stringbuilder.h"

using namespace std;

StringBuilder::StringBuilder()  {
    vector = nullptr;
    size = 0;
}

StringBuilder::StringBuilder(const char* str)  {
    int len = -1;
    while (str[++len]);

    size = len;
    vector = new int[size + 1];

    for (int i = 0; str[i]; i++) {
        vector[i] = str[i];
    }
}

char StringBuilder::charAt(int index) {

    return char(this->getElement(index));
}


StringBuilder& StringBuilder::operator + (char c){
    int data = c;
    this->add(data);

    return *this;
}

istream &operator >> (istream &is, StringBuilder &str)  {
    int ios_size = 0;
    is.sync();
    StringBuilder temp("");

    while (is.peek() != 10)  {
        temp = temp + char(is.get());
        ios_size++;
    }
    cout << temp;
    delete[] str.vector;

    str.size = temp.size;
    str.vector = new int[str.size];
    str = temp;

    return is;
}

ostream &operator << (ostream &os, StringBuilder &str)  {
    for(int i = 0; i < str.size; i++)
        os << char(str[i]);
    return os;
}



bool StringBuilder::operator== (int length) {
    return size == length;
}


StringBuilder& StringBuilder::operator= (std::string newStr){
    setString(newStr);
    return *this;
}

void StringBuilder::setString(std::string newStr) {
    delete[] vector;
    vector = new int[newStr.length()];
    size = newStr.length();

    for (int i = 0; i < newStr.length(); i++) {
        vector[i] = newStr[i];
    }

    size = newStr.length();
}

void StringBuilder::setString(char* newStr) {
    delete[] vector;

    int newLength = -1;
    while(newStr[++newLength]);

    vector = new int[newLength];

    for (int i = 0; i < newLength; i++) {
        vector[i] = newStr[i];
    }

    size = newLength;
}

StringBuilder& StringBuilder::operator= (char* newStr) {
   setString(newStr);
   return *this;
}

bool StringBuilder::endsWith(StringBuilder& obj) {
    if (obj.size > size) {
        return false;
    }
    else {
        for (int i = size - obj.size; i < size; i++) {
            if (vector[i] != obj[obj.size - size + i])
                return false;
        }
        return true;
    }
}

bool StringBuilder::startsWith(StringBuilder& obj) {
    if (obj.size > size) {
        return false;
    }
    else {
        for (int i = 0; i < obj.size; i++) {
            if (vector[i] != obj[i])
                return false;
        }
        return true;
    }
}

int StringBuilder::indexOf(StringBuilder& obj) {
    int i = -1;
    int res = 0;
    bool result;

    do {
        i++;
        result = false;

        if (vector[i] == obj[0] && obj.size > 1) {
            result = true;
            for (int j = 1; j < obj.size; j++) {
                if (vector[i + j] != obj[j]) {
                    result = false;
                    break;
                }

                if (result && j == obj.size - 1) {
                    res = i;
                    break;
                }
            }
        }
        else if (vector[i] == obj[0] && obj.size == 1) {
            result = true;
            res = i;
        }

    } while (obj.size < size - i && result != true);

    if (result == true)
        return res;
    else
        return size;
}

StringBuilder::~StringBuilder() {
   delete[] vector;
}
