#include <iostream>

using namespace std;

int main()
{
    int a,b;

    cout << "整数a : ";
    cin >> a;

    cout << "整数b : ";
    cin >> b;

    int min, max;

    if(a < b) {
        min = a;
        max = b;
    } else {
        min = b;
        max = a;
    }

    cout << "小さいほうの値は" << min << "です。\n";
    cout << "大きいほうの値は" << max << "です。\n";
}