#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#pragma once
#include "stringbuilder.h"


class LinkedList {
public:
    struct Node {
        Node* next;
        Node* prev;
        StringBuilder data;
    };

    LinkedList();//+

    void addLast(StringBuilder& obj);
    void add(StringBuilder& obj);

    void removeFirst();
    void removeLast();
    void remove();

    Node* getNext();
    Node* getPrev();
    Node* getHead();
    Node* getTail();
    Node* goHead();
    Node* goTail();
    Node* goNext();
    Node* goPrev();

    int getSize();

    StringBuilder& getFirst();
    StringBuilder& getLast();
    StringBuilder& getData();

    StringBuilder& swap(int i, int j);
//    LinkedList& operator= (LinkedList& obj);
    StringBuilder& operator[] (int index);

    ~LinkedList();

private:
    Node* head;
    Node* tail;
    Node* data;
    int size;
};

#endif // LINKEDLIST_H
