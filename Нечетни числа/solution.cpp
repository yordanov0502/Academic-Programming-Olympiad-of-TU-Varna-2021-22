#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   
    int T,N,M,min,quantity;
    bool flag;
    cin >> T;

    for (int i = 0; i < T; i++) 
    {
        cin >> N >> M;

        int* numbers = new int[N];

        quantity=0;
        min = -777;
        flag = true;

        for (int i = 0; i < N; ++i) 
        {
            cin >> numbers[i];

            if (numbers[i] % 2 == 1) 
            {
                quantity++;
                if (flag) { min = numbers[i]; flag = false; continue; }
                if (min > numbers[i]) { min = numbers[i];}
            }
        }

        if (min != -777) 
        {
            for (int i = 0; i < N; i++) 
            {
                if (numbers[i] % 2 == 0)
                {
                    if (numbers[i] + min <= M) {quantity++;}
                }
            }
        }
        cout << quantity << endl;
        delete[] numbers;
    }
    return 0;
}