#include <iostream>
#include <stringbuilder.h>

using namespace std;


int main() {
    StringBuilder s;
    StringBuilder s1("1qwe");
    cout << "s1 = " << s1 << endl;
    StringBuilder s2(s1);
    cout << "s2 = " << s2 << endl;
    cout << "ls1 = " << s1.getLength() << "; ls2 = " << s2.getLength() << endl;
    s1 = s1.concatWith(s2);
     cout << "ls1 = " << s1.getLength() << endl;
    cout << "s1 conc s2 = " << s1 << endl;
    cout << "Length s1 = " << s1.getLength() << endl;
    cout << "char at 1 s1 = " << s1[1] << ".\n";
    StringBuilder s4(s1);
    if (s1 == s4) {
        cout << "true, s1 = s4" << endl;
    }
    if (s1 == s2) {
        cout << "false ERROR" << endl;
    }
    StringBuilder hello("Hello ");
    StringBuilder world("World!!!");
    hello = hello + world;
    cout << "hello = " << hello << endl;
    hello += world;
    cout << "hello = " << hello << endl;
    hello = world + 'c';
    cout << "hello = " << hello << endl;
    string str = "i'm string";
    s1 = hello;
    cout << "s1 = hello" << s1 << endl;
    s1 = str;
    cout << "its str? " << s1 << endl;
    s1[1]++;
    cout << "s1++ = " << s1;
    if (s1 == s1.getLength()) {
        cout << "length true" << endl;
    }




    cout << "Enter: ";
    cin >> s;
    cout << s << endl;


    return 0;
}
