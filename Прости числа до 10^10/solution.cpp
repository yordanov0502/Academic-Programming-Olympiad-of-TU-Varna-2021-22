#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool Check(long long n) 
{
    long long a = 2;
    while (a * a <= n) 
    {
        if (n % a == 0)  {return false;}
        a += 1;
    }
    return true;
}


int main() {
   
    int N;//broj chisla
    long long chislo;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> chislo;
        if (Check(chislo)) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}
