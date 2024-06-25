#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> // std::exit を使用するために追加

using namespace std;

int main() {
    vector<int> numbers;
    int num;

    do {
        cout << "数字を入力してください (終了するには -1 を入力): ";
        if (!(cin >> num)) { // 数字以外の入力を検出
            cout << "エラー: 数字以外の文字が入力されました。プログラムを終了します。" << endl;
            std::exit(EXIT_FAILURE); // プログラムを強制終了
        }
        if (num != -1) {
            numbers.push_back(num);
        }
    } while (num != -1);

    int order;
    do {
        cout << "1: 昇順, 2: 降順 どちらでソートしますか？ ";
        if (!(cin >> order)) { // 数字以外の入力を検出
            cout << "エラー: 数字以外の文字が入力されました。プログラムを終了します。" << endl;
            std::exit(EXIT_FAILURE); // プログラムを強制終了
        }
        if (order == 1) {
            sort(numbers.begin(), numbers.end());
        } else if (order == 2) {
            sort(numbers.begin(), numbers.end(), greater<int>());
        }
    } while (order != 1 && order != 2);

    cout << "ソートされた数字: ";
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}
