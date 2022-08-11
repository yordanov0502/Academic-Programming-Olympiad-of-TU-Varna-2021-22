#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N; //vidove bira
    int S; //budget
    int Li; //cena za otdelen vid bira

    while (true)
    {
        cin >> N;
        if (N == 0) 
            break;
        
        cin >> S;
       

        int* prices = new int[N]; //masiv ot biri


        for (int i = 0; i < N; i++)
        {
            cin >> Li;
            while (Li < 1 || Li>1000000)
            {
                cin >> Li;
            }

            prices[i] = Li;
        }


        sort(prices, prices + N); 


        int IMAX = N - 1;
        int IMIN = 0;

        while (prices[IMAX] + prices[0] > S && IMAX > 0)
        {
            IMAX--;
        }

        while (prices[IMAX] + prices[IMIN] <= S && IMIN < N - 1)
        {
            IMIN++;
        }

        long long counter = 0;
       

        while (IMAX > IMIN)
        {
            counter = counter + IMIN;
            IMAX--;

            while (prices[IMAX] + prices[IMIN] <= S && IMIN < N - 1)
            {
                IMIN++;
            }

        }

        counter += (IMAX + 1) * IMAX / 2;
        

        
        cout << counter << endl;
    }


    return 0;
}
