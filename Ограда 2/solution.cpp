#include <iostream>
using namespace std;

int main()
{
    int T;//broj testove
    cin >> T;
    
    int N,x,y, xmin, xmax, ymin, ymax;

    for(int i=0;i<T;i++)
    {
        xmin = ymin = 1000;
        xmax = ymax = -1000;
        cin >> N;//broj durveta

        for (int i = 0; i < N; i++)
        {
            cin >> x;
            if (x > xmax) { xmax = x; }
            if (x < xmin) { xmin = x; }

            cin >> y;
            if (y > ymax) { ymax = y; }
            if (y < ymin) { ymin = y; }
        }
        cout << 4 * (max( xmax - xmin, ymax - ymin ) + 2)<<endl;
    }
    return  0;
}