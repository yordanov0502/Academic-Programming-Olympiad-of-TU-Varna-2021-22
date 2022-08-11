#include <iostream>
using namespace std;

int getBinaryWeight(long N, int table[])
{
    long firstPart = (N >> 15);

    long secondPart = N - (firstPart << 15);

    return table[(int)firstPart] + table[(int)secondPart];
}

int main()
{
    unsigned int testove;
    cin >> testove;

    unsigned int N, F, A, B, M; int sum;

    
    int SIZE = 1 << (15 + 1);//65536
    int* table = new int[SIZE];

    long S_previous, S_next;

    for (int i = 0; i < SIZE; i++)
    {
        table[i] = __builtin_popcount(i);
    }

    for (unsigned int i = 0; i < testove; i++)
    {
        cin >> N >> F >> A >> B >> M;

        S_previous = F % M;
     
        sum = getBinaryWeight(S_previous,table);

        for (unsigned int i = 1; i < N; i++)
        {
            S_next = (S_previous * A + B) % M;

            S_previous = S_next;
           
            sum+= getBinaryWeight(S_next, table);
        }
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}