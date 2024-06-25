#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int countWordsInFile(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "ファイルを開けませんでした: " << fileName << endl;
        return -1; // ファイルが開けなかった場合にエラーを示すために -1 を返す
    }

    string word;
    int count = 0;

    while (file >> word) { // スペースで区切られた単語を読み込む
        count++;
    }

    file.close();
    return count;
}

int main() {
    string fileName = "word.txt"; // ファイル名を固定

    int wordCount = countWordsInFile(fileName);
    if (wordCount == -1) {
        // ファイルオープン失敗の処理
        cout << "エラー: ファイルを開けませんでした。" << endl;
    } else if (wordCount == 0) {
        // 単語が0個の場合の処理
        cout << "ファイル '" << fileName << "' には単語が含まれていません。" << endl;
    } else {
        // 通常の単語数表示
        cout << "ファイル '" << fileName << "' には " << wordCount << " 個の単語が含まれています。" << endl;
    }

    return 0;
}