class StringBuilder {
public:
    StringBuilder(const char* newStr);
    StringBuilder(const StringBuilder &newStr);
    ~StringBuilder();

    StringBuilder concatWith(StringBuilder newStr);
    int getLength();
    char charAt(int index);

    void setString(const char* str);
    void printStr();
    char* getString();

    char** trim (char splitSymbol);//**//

private:
    char* string;
    int length;
};
