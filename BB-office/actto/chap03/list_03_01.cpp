#include <string>
#include <iostream>

using namespace std;

int main ()
{
    string retry;

    do {
        int month;
        cout << "季節を求めます。 \n何月ですか : ";
        cin >> month;

        if (month >= 3 && month <= 5) 
            cout << "それは春です。 \n";
        else if (month >= 6 && month <= 8)
            cout << "それは夏です。 \n";
        else if (month >= 9 && month <= 11)
            cout << "それは秋です。 \n";
        else if (month == 12 || month == 1 || month == 2)
            cout << "それは冬です。 \n";
        else
            cout << "\aそんな月はありませんよ。 \n";
  
        cout << "もう一度？ Y・・・Yes/N・・・No : ";
        cin >> retry;
    } while (retry == "Y" || retry == "y");
}