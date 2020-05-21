#include"vector.h"

Vector::Vector() {
    vector = nullptr;
    size = 0;
}

Vector::Vector(int size) {
    this->size = size;
    vector = new int[size];
}

Vector::Vector(Vector& obj) {
    size = obj.size;

    vector = new int[size];

    for (int i = 0; i < size; i++) {
        vector[i] = obj.vector[i];
    }
}

Vector& Vector::addAll(Vector& obj) {
    Vector copy(*this);
    size += obj.size;

    delete[] vector;
    vector = new int[size + obj.size];

    for (int i = 0; i < size; i++) {
        if (i < copy.size) {
            vector[i] = copy.vector[i];
        }
        else {
            vector[i] = obj.vector[i - copy.size];
        }
    }

    return *this;
}

Vector& Vector::create(int size) {
    if (vector != nullptr)
        delete[] vector;

    this->size = size;

    vector = new int[size];

    for (int i = 0; i < size; i++) {
        vector[i] = 0;
    }

    return *this;
}

void Vector::setElement(int index, int& data) {
        if (index < 0 || index > size) {
            throw invalid_argument("Index < 0 or > size");
        }

        vector[index] = data;
}

void Vector::create(Vector& obj) {
    size = obj.size;
    if (vector != nullptr && (&obj != this)) {
        delete[] vector;
    }

    if (&obj == this) {
        Vector copy(obj);
        delete[] vector;
        vector = new int[size];

        for (int i = 0; i < size; i++) {
            vector[i] = copy.vector[i];
        }
    }
    else {
        vector = new int[size];

        for (int i = 0; i < size; i++) {
            vector[i] = obj.vector[i];
        }
    }
}

void Vector::add(int& data) {
    Vector copy(*this);
    size++;

    delete[] vector;
    vector = new int[size];

    for (int i = 0; i < size - 1; i++) {
        vector[i] = copy.vector[i];
    }

    vector[size - 1] = data;
}

int Vector::get(int index) {
    if (index < 0 || index > size) {
        throw invalid_argument("Index < 0 or > size");
    }

    return vector[index];
}

int Vector::getSize() {
    return size;
}

ostream& operator<< (ostream& os, Vector& obj) {
    for (int i = 0; i < obj.size; i++) {
        os << obj[i];
    }

    return os;
}

Vector& Vector::operator= (Vector& obj) {
    if (!(obj == *this)) {
        this->create(obj);
    }

    return *this;
}

Vector& Vector::operator+= (Vector& obj) {
    this->addAll(obj);

    return* this;
}

Vector& Vector::operator+ (Vector& obj) {
    Vector copy(*this);
    copy.addAll(obj);

    return copy;
}

Vector& Vector::operator+ (int& data) {
    Vector copy(*this);
    copy.add(data);

    return copy;
}

Vector& Vector::operator- (int amount) {
    if (amount >= size) {
        throw invalid_argument("amount >= size");
    }

    Vector copy(*this);

    delete[] vector;
    vector = new int[size - amount];

    for (int i = 0; i < size - amount; i++) {
        vector[i] = copy[i];
    }

    size = size - amount;

    return *this;
}

Vector& Vector::operator-- (int data) {
    if (size == 0) {
        throw invalid_argument("amount >= size");
    }

    Vector copy(*this);

    delete[] vector;
    vector = new int[size - 1];

    for (int i = 0; i < size - 1; i++) {
        vector[i] = copy[i];
    }

    size--;

    return *this;
}

Vector& Vector::operator-- () {
    if (size == 0) {
        throw invalid_argument("amount >= size");
    }

    Vector copy(*this);

    delete[] vector;
    vector = new int[size - 1];

    for (int i = 0; i < size - 1; i++) {
        vector[i] = copy[i + 1];
    }

    size--;

    return *this;
}

int& Vector::operator[] (int index) {
    if (index < 0) {
        throw invalid_argument("amount >= size");
    }
    return vector[index];
}

bool Vector::operator== (Vector& obj) {
    if (obj.size != size)
        return false;
    else {
        for (int i = 0; i < size; i++) {
            if (!(vector[i] == obj.vector[i]))
                return false;
        }
        return true;
    }
}


// Created by Malova yana 19.05.2020
string Vector::toString() {
    string str;

    for (int i = 0; i < size; i++) {
        str += (*this)[i];
    }

    return str;
}

// Created by Malova yana 19.05.2020
StringSerializable& Vector::parse(string str) {
    int data;
    for(int i = 0; i < str.length(); i++) {
        data = str[i];
        this->add(data);
    }
    return *this;
}

Vector::~Vector() {
    delete[] vector;
}


