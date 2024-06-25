// 0,1,2のみを受け付ける

#include <iostream>

using namespace std;

int main ()
{
    int hand;

    do {
        cout << "手を選んでください (0_グー/1_チョキ/2_パー) : ";
        cin >> hand;
    } while (hand < 0 || hand > 2);

    switch (hand) {
        case 0 : cout << "グー\n"; break;
        case 1 : cout << "チョキ\n"; break;
        case 2 : cout << "パー\n"; break;
    }
}