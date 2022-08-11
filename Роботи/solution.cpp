#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int T;//broj testove
    cin >> T;

    int N, M;
    int left, right;
    int counter = 0;

    for (int t = 0; t < T; t++)
    {
        cin >> N >> M;

        int* robots = new int[N];

        for (int i = 0; i < N; i++)
        {
            cin >> robots[i];
        }

            sort(robots, robots + N);

            int indexL = 0;
            int indexR = 1;
            left = robots[indexL];
            right = robots[indexR];

            for (int i = 1; i < N; i++)
            {
                if (right - left > M) 
                { 
                    //cout << "left=" << left << " right=" << right << endl;
                    left = robots[++indexL]; 
                    right = robots[++indexR];
                   
                }

                else {
                   // cout << "left=" << left << " right=" << right << endl; 
                    counter++; right = robots[++indexR];
                }
            }
            cout << counter+1 << endl;
            delete[] robots;
            counter = 0;
        
    }
    return 0;
}