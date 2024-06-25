#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    const int row = 4;
    const int col = 5;

    int myArray[row][col];

    // ファイルを開く
    ifstream inputfile("hairetsu_connection.txt");

    if (!inputfile.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    string line;
    // 最初のヘッダー行を読み飛ばす
    getline(inputfile, line);

    // ファイルから配列に入力を読み込むループ
    for (int r = 0; r < row; r++) { // 行のループ
        for (int c = 0; c < col; c++) { // 列のループ
            inputfile >> myArray[r][c]; // ファイルから入力を取得して配列に格納
        }
    }

    // ファイルを閉じる
    inputfile.close();

    // 配列の内容をコンソールに表示
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cout << myArray[r][c] << "\t";
        }
        cout << endl;
    }

    // 出力ファイルを開く
    ofstream outputfile("output.txt");

    if (!outputfile.is_open()) {
        cout << "Error opening output file" << endl;
        return 1;
    }

    // ヘッダー行を書き込む
    outputfile << "no\ta\tb\tc\td" << endl;

    // 配列の内容をファイルに書き込むループ
    for (int r = 0; r < row; r++) { // 行のループ
        for (int c = 0; c < col; c++) { // 列のループ
            outputfile << myArray[r][c];
            if (c < col - 1) {
                outputfile << "\t";
            }
        }
        outputfile << endl;
    }

    // 出力ファイルを閉じる
    outputfile.close();

    return 0;
}
