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

StringBuilder::StringBuilder(StringBuilder& obj) {
    size = obj.size;
    vector = new int[size];

    for (int i = 0; i < size; i++) {
        vector[i] = obj[i];
    }
}

int StringBuilder::get(int index) {

    return vector[index];
}


StringBuilder& StringBuilder::operator + (char c){
    int data = c;
    this->add(data);

    return *this;
}

char& StringBuilder::operator[](int index) {
    if (index >= size || index < 0) throw invalid_argument("invalid index");
    int* intPtr = &vector[index];
    char* charPtr = reinterpret_cast<char*>(intPtr);

    return *charPtr;
}

StringBuilder& StringBuilder::concatWith(StringBuilder& obj) {
    (*this) += obj;
    return *this;
}

StringBuilder::operator string() {
    string obj;
    for (int i = 0; i < size; i++) {
        obj += char(vector[i]);
    }
    return obj;
}

StringBuilder& StringBuilder::operator= (StringBuilder& obj) {
    if (&obj == nullptr) {
        throw invalid_argument("nullptr in parametr");
    }
    if (!(*this == obj)){
        delete[] vector;
        size = obj.size;
        vector = new int[size];

        for (int i = 0; i < size; i++) {
            vector[i] = obj.get(i);
        }
    }

    return *this;
}

istream &operator >> (istream &is, StringBuilder &str)  {
    is.sync();
    StringBuilder temp("");

    while (is.peek() != 10)  {
        temp = temp + char(is.get());
    }

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

bool StringBuilder::operator== (StringBuilder& obj) {
    if (size == obj.size) {
        for (int i = 0; i < size; i++) {
            if (get(i) != char(obj[i]))
                return false;
        }
        return true;
    }
    else return false;
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

    int newLength = -1;
    while(newStr[++newLength]);

    delete[] vector;
    vector = new int[newLength];

    for (int i = 0; i < newLength; i++) {
        vector[i] = newStr[i];
    }

    size = newLength;
}

StringBuilder& StringBuilder::operator+ (StringBuilder& obj) {
    (*this) += obj;
    return *this;
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

bool StringBuilder::operator!= (int length) {
    return size != length;
}

bool StringBuilder::operator>= (int length) {
    return size >= length;
}

bool StringBuilder::operator<= (int length) {
    return size <= length;
}

bool StringBuilder::operator> (int length) {
    return size > length;
}

bool StringBuilder::operator< (int length) {
    return size < length;
}

bool StringBuilder::operator!= (StringBuilder& obj) {
    return !(*this == obj);
}

string StringBuilder::toString() {
    string str;

    for (int i = 0; i < size; i++) {
        str += (*this)[i];
    }

    return str;
}

StringSerializable& StringBuilder::parse(string str) {
    int data;
    for(int i = 0; i < str.length(); i++) {
        data = str[i];
        this->add(data);
    }
    return *this;
}

StringBuilder* StringBuilder::split(char cut, int& count) {
    int amount = 0;
    for (int i = 0; i < size; i++) {
        if ((*this)[i] == cut)
            amount++;
    }
    amount++;
    StringBuilder* arr = new StringBuilder[amount];
    int j = 0;

    for (int i = 0; i < amount; i++) {
        if (j < size)
            while((j < size) && (*this)[j] != cut) {
                arr[i] = arr[i] + (*this)[j];
                j++;
            }
        j++;
    }
    count = amount;
    return arr;
}

StringBuilder::~StringBuilder() {

}
