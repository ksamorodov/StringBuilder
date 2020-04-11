#include <string>


class StringBuilder {
public:
    StringBuilder(const char* newStr);
    StringBuilder(const StringBuilder &newStr);
    ~StringBuilder();
    StringBuilder(char* newStr);

    StringBuilder concatWith(StringBuilder newStr);
    int getLength();
    char charAt(int index);
    void setString(const char* str);
    char* getString();

    StringBuilder operator+ (StringBuilder secondStr);

    char* toString();
    bool equals(StringBuilder secondStr);

    char operator[] (int index);
    bool operator== (StringBuilder secondStr);
    bool operator== (int length);
    void operator+= (StringBuilder secondStr);
    void operator= (std::string newStr);
    void operator= (StringBuilder newStr);

    void setString(StringBuilder newStr);
    void setString(std::string newStr);
    void setString(char* str);

private:
    char* string;
    int length;
};

