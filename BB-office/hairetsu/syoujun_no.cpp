#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <locale>
#include <codecvt>
#include <algorithm>
#include <vector>

struct Record {
    int no;
    std::string lastName;
    std::string firstName;
    std::string kana_lastName;
    std::string kana_firstName;
    std::string mail;
};

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

    std::vector<Record> records;
    std::string line;
    while (std::getline(file, line)) {
        replace_full_width_spaces(line); // 全角スペースを半角スペースに置き換える
        std::istringstream iss(line);
        Record record;
        // 行からデータを取得
        if (iss >> record.no >> record.lastName >> record.firstName >> record.kana_lastName >> record.kana_firstName >> record.mail) {
            // Noが1から9の場合にレコードを追加
            if (record.no > 0 && record.no < 10) {
                records.push_back(record);
            }
        }
    }

    // Noでソート
    std::sort(records.begin(), records.end(), [](const Record &a, const Record &b) {
        return a.no < b.no;
    });

    // 昇順に出力
    for (const auto &record : records) {
        std::cout << record.no << record.lastName  << record.firstName << record.kana_lastName << record.kana_firstName << record.mail << std::endl;
    }

    file.close();
    return 0;
}
