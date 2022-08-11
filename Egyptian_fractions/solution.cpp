#include <iostream>
#include <numeric>
using namespace std;

int main() {

    int testove;
    cin >> testove;

    unsigned int Z;

    for (int i = 0; i < testove; i++)
    {
        cin >> Z;

                //  1/y = 1/z - 1/x
                //  1/y = (Chislitel_1 - Chislitel_2) / nok_na_Z_i_X
                //  y= nok_na_Z_i_X / (Chislitel_1 - Chislitel_2)

        unsigned int nok_na_Z_i_X;
        double Chislitel_1,Chislitel_2,y;

        for (unsigned int x = 2; x < 2 * Z; x++)
            {
                nok_na_Z_i_X = lcm(x, Z);
                Chislitel_1 = nok_na_Z_i_X / Z;
                Chislitel_2 = nok_na_Z_i_X / x;

                y = nok_na_Z_i_X / (Chislitel_1 - Chislitel_2);

                if (y < x || !((int)y==y)) { continue; }
               
                cout << x << " " << y << endl;
            }
    }
    return 0;
}