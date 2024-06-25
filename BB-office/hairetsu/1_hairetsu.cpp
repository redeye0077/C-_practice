#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::ifstream infile("hairetsu.txt");
    std::string line;
    std::vector<std::vector<int>> data;

    // ファイルが開けなかった場合のエラーチェック
    if (!infile.is_open()) {
        std::cerr << "ファイルを開けませんでした。" << std::endl;
        return 1;
    }

    // ファイルを行ごとに読み込む
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        int num;
        std::vector<int> row;

        // 行を数値に分割してベクトルに格納
        while (ss >> num) {
            row.push_back(num);
        }
        data.push_back(row);
    }

    // 2列目と3列目を出力
    for (const auto& row : data) {
        if (row.size() > 2) { // 少なくとも3列あるかチェック
            std::cout << row[1] << row[2] << std::endl;
        }
    }

    return 0;
}
