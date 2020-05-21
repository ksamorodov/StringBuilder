#include "consoleinterface.h"

ConsoleInterface::ConsoleInterface(){}

void ConsoleInterface::show() {
    system("cls");
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    cout << "╔═════════════════════════════════╗" << endl;
    cout << "║           Translator            ║" << endl;
    cout << "╚═════════════════════════════════╝" << endl;
//    cout << "╔═════════════════════════════════╗" << endl;
//    cout << "║   Press 1 to translate string   ║" << endl;
//    cout << "╚═════════════════════════════════╝" << endl;
    cout << "╔═════════════════════════════════╗" << endl;
    cout << "║   Press 1 to translate file     ║" << endl;
    cout << "╚═════════════════════════════════╝" << endl;
    cout << "╔═════════════════════════════════╗" << endl;
    cout << "║   Press q to exit               ║" << endl;
    cout << "╚═════════════════════════════════╝" << endl;
    TranslateFile tf("C:/Users/Kirill/Documents/StringBuilder/input/input.txt");
    char ch = getch();
    system("cls");
    StringBuilder str;
    StringBuilder name;
    switch (ch) {
//    case '1':
//        cout << "╔══════════════╦══════════════" << endl;
//        cout << "║Enter string: ║ ";
//        cin >> str;
//        cout << "╚══════════════╩══════════════" << endl;
//        cout << "╔══════════════╦══════════════" << endl;
//        cout << "║  Translate:  ║ " << tf.getDictionary().translateString(str) << endl;
//        cout << "╚══════════════╩══════════════" << endl;
//        break;
    case '1':
        tf.writeTranslateInFile("C:/Users/Kirill/Documents/StringBuilder/output/output.txt");
        cout << "╔═════════════════════════════════╗" << endl;
        cout << "║  Complete, check output.txt     ║" << endl;
        cout << "╚═════════════════════════════════╝" << endl;
        break;
    case 'q': return;
    }
    cout << "╔═════════════════════════════════╗" << endl;
    cout << "║   Press eny key to continye...  ║" << endl;
    cout << "╚═════════════════════════════════╝" << endl;
    getch();
    show();
}

char* iso_latin_1_to_utf8(char* buffer, char* end, unsigned char c) {
    if (c < 128) {
        if (buffer == end) {
            throw std::runtime_error("out of space");
        }
        *buffer++ = c;
    }
    else {
        if (end - buffer < 2)
        { throw std::runtime_error("out of space"); }
        *buffer++ = 0xC0 | (c >> 6);
        *buffer++ = 0x80 | (c & 0x3f);
    }     return buffer;
}
