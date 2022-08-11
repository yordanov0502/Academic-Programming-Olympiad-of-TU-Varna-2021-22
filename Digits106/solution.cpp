#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int T;
    cin >> T;

    while (T <= 0 || T >= 12)
    {
        cin >> T;
    }

    string* S = new string[T];

    for (int i = 0; i < T; i++)
    {
        while (S[i].length() <= 2 || S[i].length() > 1000000)
        {
            cin >> S[i];
        }
    }


    for (int i = 0; i < T; i++)
    {
        long long sum = 0;

        for (int j = 0; j < S[i].length(); j++)
        {
            if (S[i].at(j) < '1' || S[i].at(j) > '9') { break; }

            int temp = (int)S[i].at(j) - 48;
            sum = sum + temp;


            if (j == S[i].length() - 1) { sum = sum * (S[i].length() - 1); cout << sum << endl; }

        }
    }

    return 0;
}
