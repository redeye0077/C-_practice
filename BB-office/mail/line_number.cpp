#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string ReadLineFromFile(const string& filename, int lineNumber) {
    ifstream file(filename);
    string line;
    int currentLine = 0;

    while (getline(file, line)) {
        currentLine++;
        if (currentLine == lineNumber) {
            return line;
        }
    }

    return ""; // 行が見つからない場合は空の文字列を返す
}

int main() {
    string filename = "mail_list.txt";

    for (int lineNumber = 1; lineNumber <= 10; ++lineNumber) {
        string line = ReadLineFromFile(filename, lineNumber);
        if (line != "") {
            cout << line << endl;
        } else {
            cout << "Line " << lineNumber << " not found." << endl;
        }
    }

    return 0;
}
