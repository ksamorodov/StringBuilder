#ifndef STRINGSERIALIZABLE_H
#define STRINGSERIALIZABLE_H
#include <string>

using namespace std;

class StringSerializable {
public:
    StringSerializable();
    virtual string toString() = 0;
    virtual StringSerializable& parse(string str) = 0;
    virtual ~StringSerializable();
};

#endif // STRINGSERIALIZABLE_H
