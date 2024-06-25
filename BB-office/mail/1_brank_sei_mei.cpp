#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    std::ifstream file("himail_list.txt");
    std::string line;

    std::vector<std::string> sei;
    std::vector<std::string> mei;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string no, ssei, smei, xxx, yyy;
        if (!(iss >> no >> ssei >> smei >> xxx >> yyy)) { break; } 

        // 姓と名を配列に追加
        sei.push_back(ssei);
        mei.push_back(smei);
    }

    // Concatenate sei and mei with newline
    std::string combined;
    for (size_t i = 0; i < sei.size(); ++i) {
        combined += sei[i] + mei[i] + "\n";
    }

    // Output the concatenated string with newlines
    std::cout << "Combined with newlines:\n" << combined;

    return 0;
}
