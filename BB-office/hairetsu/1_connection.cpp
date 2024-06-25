#include <iostream>
#include <fstream>
#include <string>

int main() {
    // ファイル読み込み
    std::string filename = "connection.txt";

    std::ifstream file(filename);

    // 出力
    std::string line;
    while (std::getline(file, line)) {
        // 指定文字出力
        std::cout << line.substr(0,3)  << line.substr(3,15) << std::endl;
    }

    file.close();

    return 0;
}
