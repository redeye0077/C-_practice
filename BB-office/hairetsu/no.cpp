#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <locale>
#include <codecvt>
#include <algorithm>

void replace_full_width_spaces(std::string &str) {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring wstr = converter.from_bytes(str);
    std::replace(wstr.begin(), wstr.end(), L'　', L' '); // 全角スペースを半角スペースに置き換え
    str = converter.to_bytes(wstr);
}

int main() {
    std::ifstream file("mail_list.txt"); // ファイル名は適切に変更してください

    if (!file.is_open()) {
        std::cerr << "ファイルを開けませんでした。" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        replace_full_width_spaces(line); // 全角スペースを半角スペースに置き換える
        std::istringstream iss(line);
        int no;
        std::string lastName, firstName, kana_lastName, kana_firstName, mail;

        // 行からデータを取得
        if (iss >> no >> lastName >> firstName >> kana_lastName >> kana_firstName >> mail) {
            // Noが1から9の場合に出力
            if (no < 10) {
                std::cout << no << lastName << firstName << kana_lastName << kana_firstName << mail << std::endl;
            }
        }
    }

    file.close();
    return 0;
}
