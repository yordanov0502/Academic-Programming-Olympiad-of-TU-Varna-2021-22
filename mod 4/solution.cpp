#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long calculate(long long base, long long exp, int mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return res;
}



int main() {
    int tests;
    cin >> tests;

    while (tests <= 0 || tests >= 40)
    {
        cin >> tests;
    }

    int* b=new int[tests];
    long long* e=new long long[tests];
    int* mod=new int[tests];

    for (int i = 0; i < tests; i++)
    {
        cin >> b[i] >> e[i] >> mod[i];
    }
     

    for (int i = 0; i < tests; i++)
    {
        cout << calculate(b[i], e[i], mod[i])<<endl;
    }

    
    return 0;
}
