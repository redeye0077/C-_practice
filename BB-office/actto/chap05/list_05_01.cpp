#include <iostream>

using namespace std;

int main()
{
    int aaa, iii, uuu, eee, ooo;
    int sum = 0;

    cout << "5人の点数の合計点と平均点を求めます。\n";
    cout << "1番の点数 : "; cin >> aaa; sum += aaa;
    cout << "2番の点数 : "; cin >> iii; sum += iii;
    cout << "3番の点数 : "; cin >> uuu; sum += uuu;
    cout << "4番の点数 : "; cin >> eee; sum += eee;
    cout << "5番の点数 : "; cin >> ooo; sum += ooo;

    cout << "合計は" << sum << "点です。\n";
    cout << "平均は" << static_cast<double>(sum) / 5 << "点です。\n";
}