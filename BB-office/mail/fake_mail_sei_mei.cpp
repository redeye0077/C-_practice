#include <iostream>
#include <fstream>
#include <string>

int main() {
    // ファイル名
    std::string filename = "fake_mail_list.txt";

    // ファイルを開く
    std::ifstream file(filename);

    // ファイルから一行ずつ読み込んで処理
    std::string line;
    while (std::getline(file, line)) {
        // sei meiの文字を出力
        std::cout << line.substr(3,5) << line.substr(8,5) << std::endl;
    }

    // ファイルを閉じる
    file.close();

    return 0;
}
