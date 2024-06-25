#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main() {
    //ファイルを読み込む
    ifstream file("mail_list.txt");

    //メールアドレスの正規表現を定義
    regex emailRegex("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");

    //メールアドレスのみ出力する
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