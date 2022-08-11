#include <iostream>
#include <algorithm>
using namespace std;

int main() {
   
    int T;//broj testove
    cin >> T;

    int N;//broj kandidati
    long long EGN;
    int counter=0;

    for (int i = 0; i < T; i++)
    {
        cin >> N;

        for (int j = 0; j < N; j++)
        {
            cin >> EGN;
            if ( ((EGN / 10) % 10) % 2 == 0 ) { counter++; }
        }
        cout << counter << endl;
        counter = 0;
    }
    return 0;
}