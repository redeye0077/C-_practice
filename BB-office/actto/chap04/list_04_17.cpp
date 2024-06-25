#include <iostream>
using namespace std;

int main()
{
    enum animal { Dog, Cat, Monkey, Invalid };
    int type;

    do {
        cout << "0_犬" "1_猫" "2_猿" "3_終了 : ";
        cin >> type;
    } while (type < Dog || type >Invalid);
    
    if (type != Invalid) {
        animal selected = static_cast<animal>(type);

        switch (selected) {
            case Dog  : cout << "ワンワン!!\n"; break;
            case Cat  : cout << "ニャーオ!!\n"; break;
            case Monkey  : cout << "キッキッ!!\n"; break;
        }
    }
}