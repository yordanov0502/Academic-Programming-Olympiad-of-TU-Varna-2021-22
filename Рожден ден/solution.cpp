#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;


int main() {
   
    int T;//broj testove
    cin >> T;

    double Ha, Hb, Hc;
    double a, b, c;

    for (int i = 0; i < T; i++)
    {
        cin >> Ha >> Hb >> Hc;


        if (isinf(1 / sqrt(((1 / Ha) + (1 / Hb) + (1 / Hc)) * (-(1 / Ha) + (1 / Hb) + (1 / Hc)) * ((1 / Ha) - (1 / Hb) + (1 / Hc)) * ((1 / Ha) + (1 / Hb) - (1 / Hc)))))
        {
            cout << "INVALID" << endl;
        }

        else 
        {
            double Area = 1 / sqrt(((1 / Ha) + (1 / Hb) + (1 / Hc)) * (-(1 / Ha) + (1 / Hb) + (1 / Hc)) * ((1 / Ha) - (1 / Hb) + (1 / Hc)) * ((1 / Ha) + (1 / Hb) - (1 / Hc)));

            a = (Area * 2) / Ha;
            b = (Area * 2) / Hb;
            c = (Area * 2) / Hc;

            if (!(a + b > c || b + c > a || c + a > b)) { cout << "INVALID" << endl; }

            else { cout << std::fixed << setprecision(2) << a << " " << b << " " << c << endl;  }

        }
    }
    return 0;
}