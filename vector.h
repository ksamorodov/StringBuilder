#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <vector>

using namespace std;


class Vector {
protected:
    int* vector;
    int size;

public:
    Vector(Vector& obj);
    Vector(int size);
    Vector();

    Vector& addAll(Vector& obj);
    Vector& create(int size);
    Vector& clear();

    void setElement(int index, int& data);
    void create(Vector& obj);
    void add(int& data);

    virtual int get(int index);
    int getSize();

    friend ostream& operator<< (ostream& os, Vector& );

    Vector& operator= (Vector& obj);

    Vector& operator+= (Vector& obj);
    Vector& operator+ (Vector& obj);
    Vector& operator+ (int& data);
    Vector& operator- (int amount);
    Vector& operator-- (int data);
    Vector& operator-- ();

    int& operator[] (int index);

    virtual bool operator== (Vector& obj);

    ~Vector();
};


#endif // VECTOR_H
