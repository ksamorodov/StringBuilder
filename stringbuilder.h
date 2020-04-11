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
    StringBuilder& operator+= (StringBuilder secondStr);
    StringBuilder& operator= (std::string newStr);
    StringBuilder& operator= (StringBuilder newStr);

    void setString(StringBuilder newStr);
    void setString(std::string newStr);
    void setString(char* str);

private:
    char* string;
    int length;
};
