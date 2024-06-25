#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <locale>
#include <codecvt>
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

    // UTF-8形式のファイルの読み込み
    infile.imbue(std::locale(infile.getloc(), new std::codecvt_utf8<wchar_t>));

    std::wstring line;
    std::vector<std::vector<std::wstring>> data;

    // ファイルが開けなかった場合のエラーチェック
    if (!infile.is_open()) {
        std::wcerr << L"ファイルを開けませんでした。" << std::endl;
        return 1;
    }

    // ファイルを行ごとに読み込む
    while (std::getline(infile, line)) {
        if (line.length() < 2) {
            // 行の長さが不足している場合はスキップ
            continue;
        }

        // 1～3文字目をNoとして抽出
        std::wstring no = line.substr(0, 3);
        // 4～8文字目を姓として抽出
        std::wstring sei = line.substr(3, 5);
        // 9～13文字目を名として抽出
        std::wstring mei = line.substr(8, 5);
        // 14～21文字目をセイとして抽出
        std::wstring kana_sei = line.substr(13, 8);
        // 22～29文字目をメイとして抽出
        std::wstring kana_mei = line.substr(21, 8);
        // 30～59文字目をmailとして抽出
        std::wstring mail = line.substr(29, 30);

        // トリム処理をして余計なスペースを取り除く
        no.erase(no.find_last_not_of(L' ') + 1);
        sei.erase(sei.find_last_not_of(L'　') + 1);
        mei.erase(mei.find_last_not_of(L'　') + 1);
        kana_sei.erase(kana_sei.find_last_not_of(L'　') + 1);
        kana_mei.erase(kana_mei.find_last_not_of(L'　') + 1);
        mail.erase(mail.find_last_not_of(L'　') + 1);

        // データをベクトルに追加
        data.push_back({ no, sei, mei, kana_sei, kana_mei, mail });
    }

    // 指定列を出力
    for (const auto& row : data) {
        if (row.size() > 0) { 
            std::wcout << row[5] << std::endl;
        }
    }

    return 0;
}
