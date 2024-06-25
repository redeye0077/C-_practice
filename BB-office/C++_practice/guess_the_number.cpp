#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int main () 
{
    srand(time(NULL));

    int no = rand() % 100;
    int x;

    cout << "数当てゲーム開始!!\n";
    cout << "0 ～ 99の数を当ててください。\n";

    do {
        cout << "いくつかな : ";
        if (!(cin >> x)) { // 数字以外の入力を検出
            cout << "エラー: 数字以外の文字が入力されました。プログラムを終了します。" << endl;
            exit(EXIT_FAILURE); // プログラムを強制終了
        }
        if (x > no)
            cout << "\aもっと小さな数だよ。\n";
        else if (x < no)
            cout << "\aもっと大きな数だよ。\n";
    } while (x != no);

    cout << "正解です。\n";
}