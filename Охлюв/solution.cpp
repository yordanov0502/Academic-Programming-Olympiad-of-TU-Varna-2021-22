#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    unsigned int A, B;
    int V;
    int X;

    while(cin >> A >> B >> V)
    {
        X = (int)((V - B - 1) / (A - B)) + 1;
        cout << X <<endl;
    }

    return 0;
}
