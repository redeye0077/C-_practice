#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <locale>
#include <codecvt>
#include <set>
#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif

std::vector<std::wstring> split(const std::wstring& str, wchar_t delimiter) {
    std::vector<std::wstring> tokens;
    std::wstringstream ss(str);
    std::wstring token;
    while (std::getline(ss, token, delimiter)) {
        // 空のトークンを無視
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    return tokens;
}

int main() {
#ifdef _WIN32
    // 標準出力をUTF-8に設定
    _setmode(_fileno(stdout), _O_U8TEXT);
#endif

    std::wifstream infile("mail_list.txt");
    infile.imbue(std::locale(infile.getloc(), new std::codecvt_utf8<wchar_t>));

    std::wstring line;
    std::vector<std::vector<std::wstring>> data;
    std::set<std::wstring> seen; // 重複を避けるためのセット

    // ファイルが開けなかった場合のエラーチェック
    if (!infile.is_open()) {
        std::wcerr << L"ファイルを開けませんでした。" << std::endl;
        return 1;
    }

    // ファイルを行ごとに読み込む
    while (std::getline(infile, line)) {
        // 全角スペースで分割
        std::vector<std::wstring> parts = split(line, L'　');
        std::vector<std::wstring> row;

        // 各部分文字列を半角スペースで再分割
        for (const auto& part : parts) {
            std::vector<std::wstring> sub_parts = split(part, L' ');
            row.insert(row.end(), sub_parts.begin(), sub_parts.end());
        }

        data.push_back(row);
    }

    // 2列目と3列目を出力
    for (const auto& row : data) {
        std::wstring combined = row[1] + row[2];
        if (seen.find(combined) == seen.end()) {
            std::wcout << row[0] << combined << row[5] << std::endl;
            seen.insert(combined); // 見たものとしてセットに追加
        } 
    }

    return 0;
}
