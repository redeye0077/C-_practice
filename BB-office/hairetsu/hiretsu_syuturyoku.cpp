#include <iostream>
#include <fstream>
#include <vector>
#include <cwchar>
#include <locale>
#include <codecvt>
#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif

int main() {
#ifdef _WIN32
    // 標準出力をUTF-8に設定
    _setmode(_fileno(stdout), _O_U8TEXT);
#endif

    // UTF-8のロケールを設定
    std::wifstream infile("mail_list.txt");
    infile.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));

    if (!infile) {
        std::wcerr << L"ファイルを開けませんでした。" << std::endl;
        return 1;
    }

    std::wstring line;
    std::vector<std::vector<std::wstring>> data;

    while (std::getline(infile, line)) {
        // 1～3文字目をNoとして抽出
        wchar_t no[4] = {0};
        std::wcsncpy(no, line.c_str(), 3);

        // 4～8文字目を姓として抽出
        wchar_t sei[6] = {0};
        std::wcsncpy(sei, line.c_str() + 3, 5);

        // 9～13文字目を名として抽出
        wchar_t mei[6] = {0};
        std::wcsncpy(mei, line.c_str() + 8, 5);

        // 14～21文字目をセイとして抽出
        wchar_t kana_sei[9] = {0};
        std::wcsncpy(kana_sei, line.c_str() + 13, 8);

        // 22～29文字目をメイとして抽出
        wchar_t kana_mei[9] = {0};
        std::wcsncpy(kana_mei, line.c_str() + 21, 8);

        // 30～59文字目をmailとして抽出
        wchar_t mail[31] = {0};
        std::wcsncpy(mail, line.c_str() + 29, 30);

        data.push_back({ std::wstring(no), std::wstring(sei), std::wstring(mei), std::wstring(kana_sei), std::wstring(kana_mei), std::wstring(mail) });
    }

    // 姓の1文字目から2文字目を出力
    for (const auto& row : data) {
        std::wcout << row[1][0] << row[1][1] << std::endl;
    }

    return 0;
}
