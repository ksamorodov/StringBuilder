#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <vector>
#include <string>
#include "stringserializable.h"

using namespace std;


class Vector :  public StringSerializable {
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

    virtual string toString();
    virtual StringSerializable& parse(string str);

    virtual bool operator== (Vector& obj);

    ~Vector();
};


#endif // VECTOR_H
