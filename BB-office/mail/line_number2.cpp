#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("mail_list.txt"); // ファイル名を適切なものに変更してください
    if (!file.is_open()) {
        std::cerr << "ファイルを開けませんでした" << std::endl;
        return 1;
    }

    std::string line;
    int count = 0;
    while (std::getline(file, line)) {
        ++count;
        if (count > 1 && count < 11) {
            std::cout << line << std::endl;
        }
        if (count == 10) {
            break; // 必要な範囲の行を読み込んだらループを抜ける
        }
    }

    file.close(); // ファイルを閉じる

    return 0;
}
