#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    static int quantity[10000000];
    static int types[13000];

    int T;//broj situacii
    int N;//broj butilki
    int K;//broj vidove
    int j;
    int start = 0;

    int first = 0;//first index
    int last = 0;//last index

    int   f = 1, l;
    int best;
    
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        first = 0; 
        last = 0; 
        start = 0;
        f = 1; 
        
        cin >> N >> K; //vuvejdam broj butilki i vidove
        
        memset(types, 0, sizeof(types));//purvona4alno ystanovqvam vsi4ki vidove bira sus stojnost 0

        best = N;

        for (j = 1; j <= N; j++)
        {
            cin >> quantity[j];
        }

        j = 1;

        while (start < K)
        {
            if (!types[quantity[j]]) start++;
            l = j;
            types[quantity[j]]++;
            j++;
        }

        first = f;
        last = l;

        while (f <= N - K && l <= N)
        {
            while (types[quantity[f]] > 1)
            {
                types[quantity[f]]--;
                f++;
            }

            if (best > l - f + 1)
            {
                best = l - f + 1;
                first = f;
                last = l;
            }

            if (best == K) { break; }

            l++;

            if (l <= N) { types[quantity[l]]++; }
        }
        cout << first << " " << last << endl;
    }
    return 0;
}