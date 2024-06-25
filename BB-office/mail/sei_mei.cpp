#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // ファイル名の指定
    string filename = "mail_list.txt";

    // 繝ファイルを開く
    ifstream file(filename);

    // 1行ずつ読み出し
    string line;
    while (getline(file, line)) {
        // 指定文字出力
        cout << line.substr(3,9) << line.substr(18,9) << endl;
    }

    // ファイルを閉じる
    file.close();

    return 0;
}
