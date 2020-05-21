#include "linkedlist.h"

LinkedList::LinkedList():
    head(nullptr), tail(nullptr), data(nullptr), size(0){}

void LinkedList::addLast(StringBuilder& obj) {
    Node* temp = data;
    data = tail;
    add(obj);
    data = temp;
}

void LinkedList::add(StringBuilder& obj) {
    Node* temp = new Node;
    if (data != nullptr) {
        temp->next = data->next;
        if (data->next == nullptr)
            tail = temp;
    }
    else
        temp->next = nullptr;

    temp->data = obj;

    if (head != nullptr) {
        temp->prev = data;
        data->next = temp;
        data = temp;
    }
    else {
        temp->prev = nullptr;
        head = tail = data = temp;
    }
    size++;
}

void LinkedList::remove() {
    if (head != nullptr && head != tail) {
        if (data != head && data != tail) {
            data->prev->next = data->next;
            data->next->prev = data->prev;
            data = data->prev;
        }
        else if (data == tail) {
            tail = data->prev;
            tail->next = nullptr;
            data = tail;
        }
        else if (data == head) {
            head = data->next;
            head->prev = nullptr;
            data = head;
        }
    }
}

void LinkedList::removeLast() {
    Node* temp = data;
    data = tail;
    remove();
    data = temp;
}

void LinkedList::removeFirst() {
    Node* temp = data;
    data = head;
    remove();
    data = temp;
}

LinkedList::Node* LinkedList::getNext() {
    return data->next;
}

LinkedList::Node* LinkedList::getPrev() {
    return data->prev;
}

LinkedList::Node* LinkedList::getHead() {
    return head;
}

LinkedList::Node* LinkedList::getTail() {
    return tail;
}

StringBuilder& LinkedList::getData() {
    return data->data;
}

LinkedList::Node* LinkedList::goHead() {
    data = head;
    return data;
}

LinkedList::Node* LinkedList::goTail() {
    data = tail;
    return data;
}

LinkedList::Node* LinkedList::goNext() {
    data = data->next;
    return data;
}

LinkedList::Node* LinkedList::goPrev() {
    data = data->prev;
    return data;
}

StringBuilder& LinkedList::getFirst() {
    return head->data;
}

StringBuilder& LinkedList::getLast() {
    return tail->data;
}

int LinkedList::getSize() {
    return size;
}

StringBuilder& LinkedList::swap(int i, int j) {
    goHead();
    for (int k = 0; k < i; k++) {
        goNext();
    }

    StringBuilder iStr = data->data;
    cout << "This is i: " << iStr << endl;
    goHead();
    for (int k = 0; k < j; k++) {
        goNext();
    }
    StringBuilder jStr = data->data;
    cout << "This is j: " << data->data << endl;
    data->data = iStr;
    goHead();
    for (int k = 0; k < i; k++) {
        goNext();
    }
    data->data = jStr;

    return jStr;
}

//LinkedList& LinkedList::operator= (LinkedList& obj) {
//    while (head != nullptr) {
//        tail = head->next;
//        delete head;
//        head = tail;
//    }
//    size = 0;
//    head = nullptr;
//    tail = nullptr;
//    data = nullptr;
//    while (obj.getNext()) {
//        add(obj.getData());
//    }
//}

StringBuilder& LinkedList::operator[] (int index) {
    goHead();
    for (int i = 0; i < index; i++) {
        goNext();
    }
    return data->data;
}

LinkedList::~LinkedList() {
//    while (head != nullptr) {
//        tail = head->next;
//        delete head;
//        head = tail;
//    }
}
