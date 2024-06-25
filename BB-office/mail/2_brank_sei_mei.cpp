#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <locale>
#include <codecvt>

void replace_full_width_spaces(std::string &str) {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring wstr = converter.from_bytes(str);
    std::replace(wstr.begin(), wstr.end(), L'　', L' '); // 全角スペースを半角スペースに置き換え
    str = converter.to_bytes(wstr);
}

int main() {
    std::ifstream file("mail_list.txt"); // ファイルを開く
    if (!file) {
        std::cerr << "ファイルを開くことができませんでした。" << std::endl;
        return 1;
    }

    std::string line;

    while (std::getline(file, line)) { // 1行ずつ読み込む
        replace_full_width_spaces(line); // 全角スペースを半角スペースに置き換え
        std::istringstream iss(line);
        std::string no, first_name, last_name, fake;

        if (iss >> no >> last_name >> first_name >> fake) { // スペース区切りで分割
            std::cout << last_name << first_name << std::endl;
        }
    }

    file.close(); // ファイルを閉じる

    return 0;
}
