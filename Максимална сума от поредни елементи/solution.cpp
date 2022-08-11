#include <iostream>
#include<climits>
using namespace std;

int main() {
    
    int N;
    cin >> N;

    int* A = new int[N];

    long long maxSum = INT_MIN;
    long long currentSum = 0;

    for(int i=0;i<N;i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        currentSum += A[i];

        if (currentSum < 0) {currentSum = 0;}

        maxSum = max(maxSum, currentSum);
    }
    
    cout << maxSum;



    return 0;
}
