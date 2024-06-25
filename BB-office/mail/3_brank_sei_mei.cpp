#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <locale>
#include <codecvt>
#include <vector>

// 全角スペースを半角スペースに置き換える関数
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
    std::vector<std::vector<std::string>> data; // データを格納する2次元配列

    while (std::getline(file, line)) { // 1行ずつ読み込む
        replace_full_width_spaces(line); // 全角スペースを半角スペースに置き換え
        std::istringstream iss(line);
        std::string no, last_name, first_name, fake;

        if (iss >> no >> last_name >> first_name >> fake) { // スペース区切りで分割
            data.push_back({no, last_name, first_name, fake}); // 2次元配列に格納
        }
    }

    file.close(); // ファイルを閉じる

    // データを出力
    for (const auto& row : data) {
        std::cout << row[1]  << row[2] << std::endl;
    }

    return 0;
}
