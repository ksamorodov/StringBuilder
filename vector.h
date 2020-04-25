#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <vector>

using namespace std;


template <class T>
class Vector {
private:
    T* vector;
    int size;

public:
    Vector();
    Vector(int size);
    Vector(const Vector<T>& obj);

    Vector<T>& addAll(Vector<T>& obj);
    Vector& create(int size);
    Vector& clear();

    void setElement(int index, T& data);
    void create(Vector<T>& obj);
    void add(T& data);

    T& getElement(int index);
    int getSize();

    //friend ostream& operator<< (ostream& os, Vector<T>& );

    Vector<T>& operator= (Vector<T>& obj);

    Vector<T>& operator+= (Vector<T>& obj);
    Vector<T>& operator+ (Vector<T>& obj);
    Vector<T>& operator+ (T& data);
    Vector<T>& operator- (int amount);
    Vector<T>& operator-- (int data);
    Vector<T>& operator-- ();

    T& operator[] (int index);

    bool operator== (Vector<T>& obj);

    //StringBuilder& vectorToStringBuilder();

    ~Vector();
};

template<class T>
Vector<T>::Vector() {
    vector = nullptr;
    size = 0;
}

template<class T>
Vector<T>::Vector(int size) {
    this->size = size;
    vector = new T[size];
}

template<class T>
Vector<T>::Vector(const Vector<T>& obj) {
    size = obj.size;

    vector = new T[size];

    for (int i = 0; i < size; i++) {
        vector[i] = obj.vector[i];
    }
}

template<class T>
Vector<T>& Vector<T>::addAll(Vector<T>& obj) {
    Vector copy(*this);
    size += obj.size;
    delete[] vector;

    vector = new T[size + obj.size];

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

template<class T>
Vector<T>& Vector<T>::create(int size) {
    if (vector != nullptr)
        delete[] vector;

    this->size = size;

    vector = new T[size];

    for (int i = 0; i < size; i++) {
        vector[i] = 0;
    }

    return *this;
}

template<class T>
Vector<T>& Vector<T>::clear() {
    size = 0;
    delete[] vector;
    return *this;
}

template<class T>
void Vector<T>::setElement(int index, T& data) {
        if (index < 0 || index > size) {
            throw invalid_argument("Index < 0 or > size");
        }

        vector[index] = data;
}

template<class T>
void Vector<T>::create(Vector<T>& obj) {
    size = obj.size;
    if (vector != nullptr && (&obj != this)) {
        delete[] vector;
    }

    if (&obj == this) {
        Vector copy(obj);
        delete[] vector;
        vector = new T[size];

        for (int i = 0; i < size; i++) {
            vector[i] = copy.vector[i];
        }
    }
    else {
        vector = new T[size];

        for (int i = 0; i < size; i++) {
            vector[i] = obj.vector[i];
        }
    }
}

template<class T>
void Vector<T>::add(T& data) {
    Vector copy(*this);
    size++;
    delete[] vector;

    vector = new T[size];

    for (int i = 0; i < size - 1; i++) {
        vector[i] = copy.vector[i];
    }

    vector[size - 1] = data;
}

template<class T>
T& Vector<T>::getElement(int index) {
    if (index < 0 || index > size) {
        throw invalid_argument("Index < 0 or > size");
    }

    return vector[index];
}

template<class T>
int Vector<T>::getSize() {
    return size;
}

//template<class T>
//ostream& operator<< (ostream& os, Vector<T>& obj) {
//    for (int i = 0; i < obj.size; i++) {
//        obj.operator<<(os, obj[i]);
//        //os << obj[i] << ", ";
//    }
//    //os << obj[obj.size - 1];

//    return os;
//}

template<class T>
Vector<T>& Vector<T>::operator= (Vector<T>& obj) {
    this->create(obj);

    return *this;
}

template<class T>
Vector<T>& Vector<T>::operator+= (Vector<T>& obj) {
    this->addAll(obj);

    return* this;
}

template<class T>
Vector<T>& Vector<T>::operator+ (Vector<T>& obj) {
    this->addAll(obj);

    return *this;
}

template<class T>
Vector<T>& Vector<T>::operator+ (T& data) {
    this->add(data);

    return *this;
}

template<class T>
Vector<T>& Vector<T>::operator- (int amount) {
    if (amount >= size) {
        throw invalid_argument("amount >= size");
    }

    Vector copy(*this);
    delete[] vector;

    vector = new T[size - amount];

    for (int i = 0; i < size - amount; i++) {
        vector[i] = copy[i];
    }

    size = size - amount;

    return *this;
}

template<class T>
Vector<T>& Vector<T>::operator-- (int data) {
    if (size == 0) {
        throw invalid_argument("amount >= size");
    }

    Vector copy(*this);
    delete[] vector;

    vector = new T[size - 1];

    for (int i = 0; i < size - 1; i++) {
        vector[i] = copy[i];
    }

    size--;

    return *this;
}

template<class T>
Vector<T>& Vector<T>::operator-- () {
    if (size == 0) {
        throw invalid_argument("amount >= size");
    }

    Vector copy(*this);
    delete[] vector;

    vector = new T[size - 1];

    for (int i = 0; i < size - 1; i++) {
        vector[i] = copy[i + 1];
    }

    size--;

    return *this;
}

template<class T>
T& Vector<T>::operator[] (int index) {
    return vector[index];
}

template<class T>
bool Vector<T>::operator== (Vector<T>& obj) {
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

template<class T>
Vector<T>::~Vector() {
    delete[] vector;
}

#endif // VECTOR_H
