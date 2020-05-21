#include "translatefile.h"

TranslateFile::TranslateFile(const char* path) : dict("C:/Users/Kirill/Documents/StringBuilder/input/default_dict.txt") {
    ifstream fin(path);
    if (!fin.is_open()) {
        throw invalid_argument("File can't be opened in translate file");
    }
    string s;
    StringBuilder str;
    while(getline(fin, s)) {
        str = s;
        text.add(str);
    }
}

void TranslateFile::writeTranslateInFile(const char* path) {
    ofstream fout;
    fout.open(path);
    text.goHead();
    for (int i = 0; i < text.getSize(); i++) {
        fout << dict.translateString(text.getData()) << endl;
        text.goNext();
    }
    fout.close();
}

Dictionary& TranslateFile::getDictionary() {
    return dict;
}
