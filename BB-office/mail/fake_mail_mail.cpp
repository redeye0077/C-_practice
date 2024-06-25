#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main() {
    ifstream file("fake_mail_list.txt");

    regex emailRegex("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");

    string line;
    while (getline(file, line)) {
        smatch match;
        if (regex_search(line, match, emailRegex)) {
            cout << match[0] << endl;
        }
    }

    file.close();
    return 0;
}
