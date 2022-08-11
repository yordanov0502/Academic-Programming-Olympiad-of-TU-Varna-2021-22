#include <iostream>
using namespace std;

int main() {
 
    int T;
    cin >> T;//broj testove

    int N;
    int OneThird;
    int TwoThird;
    int Agneta;

    for (int i = 0; i < T; i++)
    {
        cin >> N;

        OneThird = (N / 3) * 2;

        TwoThird = (N / 2) * 1;

        Agneta = OneThird + TwoThird;

        if (Agneta % 2 == 1) 
        {
            Agneta--;
            Agneta = Agneta / 2;
        }

        else { Agneta = Agneta / 2; }

        cout << N + Agneta << endl;
    }
    return 0;
}