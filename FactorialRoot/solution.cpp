#include<iostream>
using namespace std;

int main() 
{
    int T, N, size = 0, limit[100];

    cin >> T;
    
    for (int i = 0; i < T; i++) 
    {
        cin >> N;
        
        if (N == 1) {limit[size++] = 1;}

        else if (N == 2) {limit[size++] = 2;}

        else if (N == 3) {limit[size++] = 6;}

        else if (N == 4) {limit[size++] = 6;}

        else if (N == 5) {limit[size++] = 3;}

        else {limit[size++] = 9;}
    }

    for (int i = 0; i < size; i++) 
    {
        cout << limit[i] << endl;
    }
    
    return 0;
}