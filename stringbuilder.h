class StringBuilder
{
public:
    StringBuilder();
    StringBuilder(const char* newStr);
    StringBuilder(const StringBuilder &newStr);

    StringBuilder concatWith(StringBuilder newStr);
    int getLength();
    char charAt(int index);

    void setString(const char* str);
    void printStr();
    char* getString();

private:
    char* string;
    int length;
};
