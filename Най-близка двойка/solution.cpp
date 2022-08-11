#include <iostream>
#include <cfloat>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <vector>
#include <iomanip>

using namespace std;

struct poi
{
    double poi1, poi2;
};

inline int Comp_poi1(const void* x, const void* b)
{
    poi* p1 = (poi*)x, * pnt2 = (poi*)b;
    return (p1->poi1 - pnt2->poi1);
}

inline int Comp_poi2(const void* x, const void* y)
{
    poi* pnt1 = (poi*)x, * pnt2 = (poi*)y;
    return (pnt1->poi2 - pnt2->poi2);
}

inline double Distance(poi pnt1, poi pnt2) // Calculate the distance between two points
{
    return sqrt((pnt1.poi1 - pnt2.poi1) * (pnt1.poi1 - pnt2.poi1) +
        (pnt1.poi2 - pnt2.poi2) * (pnt1.poi2 - pnt2.poi2));
}

double S_Distance(poi P[], int n, poi& pnt1, poi& pnt2)
{
    double min = DBL_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (Distance(P[i], P[j]) < min) {
                min = Distance(P[i], P[j]);
                pnt1.poi1 = P[i].poi1, pnt1.poi2 = P[i].poi2;
                pnt2.poi1 = P[j].poi1, pnt2.poi2 = P[j].poi2;
            }
    return min;
}

inline double Minimum(double poi1, double poi2) // Find minimum between two values
{
    return (poi1 < poi2) ? poi1 : poi2;
}

double Closest_dist_Spoint(poi stp[], int s, double dist, poi& pnt1, poi& pnt2)  // Calculate distance beween the closest points
{
    double Minimum = dist; // Initialize the minimum distance as dist
    qsort(stp, s, sizeof(poi), Comp_poi2);
    for (int i = 0; i < s; ++i)
        for (int j = i + 1; j < s && (stp[j].poi2 - stp[i].poi2) < Minimum; ++j)
            if (Distance(stp[i], stp[j]) < Minimum)
            {
                Minimum = Distance(stp[i], stp[j]);
                pnt1.poi1 = stp[i].poi1, pnt1.poi2 = stp[i].poi2;
                pnt2.poi1 = stp[j].poi1, pnt2.poi2 = stp[j].poi2;
            }
    return Minimum;
}

double Closest_dist(poi P[], poi stp[], int n, poi& pnt1, poi& pnt2) // Calculate smallest distance.
{
    static poi pt1, pt2, pt3, pt4;
    if (n <= 3)
        return S_Distance(P, n, pt1, pt2);
    int medium = n / 2; // Calculate the mid point
    poi mediumPoint = P[medium];
    double D_Left = Closest_dist(P, stp, medium, pt1, pt2); // D_Left: left of medium point
    double D_Right = Closest_dist(P + medium, stp, n - medium, pt3, pt4); // D_Right: right side of the medium point
    if (D_Left < D_Right)
    {
        pnt1.poi1 = pt1.poi1; pnt1.poi2 = pt1.poi2; // Store the pair that has smaller distance
        pnt2.poi1 = pt2.poi1; pnt2.poi2 = pt2.poi2;
    }
    else {
        pnt1.poi1 = pt3.poi1; pnt1.poi2 = pt3.poi2;
        pnt2.poi1 = pt4.poi1; pnt2.poi2 = pt4.poi2;
    }
    double min_dist = Minimum(D_Left, D_Right);
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].poi1 - mediumPoint.poi1) < min_dist)
            stp[j++] = P[i];
    double min_dist_strip = Closest_dist_Spoint(stp, j, min_dist, pt1, pt2);
    double F_Min = min_dist;
    if (min_dist_strip < min_dist)
    {
        pnt1.poi1 = pt1.poi1; pnt1.poi2 = pt1.poi2;
        pnt2.poi1 = pt2.poi1; pnt2.poi2 = pt2.poi2;
        F_Min = min_dist_strip;
    }
    return F_Min;
}

int main() {

    int index = 0;
    double X, Y;
    double endOfTest;

    int count = 0;

    vector <double> vecX;
    vector <double> vecY;

    int broqch = 0;
    
    while (1)
    {
        
        if (cin.eof()) { break; }
       
        cin >> endOfTest;

        if (endOfTest != -1)
        {
            X = endOfTest;
            cin >> Y;
            vecX.push_back(X);
            vecY.push_back(Y);
            count++;
            index++;
            broqch=0;
        }
        

        else
        {
            if(broqch!=0) {break;}
            broqch++;
            
            double* onlyX = new double[count];
            copy(vecX.begin(), vecX.end(), onlyX);

            double* onlyY = new double[count];
            copy(vecY.begin(), vecY.end(), onlyY);

            poi* P = new poi[count];

            for (int i = 0; i < count; i++)
            {
                P[i].poi1 = onlyX[i];
                P[i].poi2 = onlyY[i];
            }

            vecX.clear(); vecY.clear();
            delete[] onlyX; delete[] onlyY;

            poi pnt1 = { INT_MAX, INT_MAX }, pnt2 = { INT_MAX, INT_MAX }; // Closest pair of points in array
            int n = index;
            qsort(P, n, sizeof(poi), Comp_poi1);
            poi* stp = new poi[n];
            cout << std::fixed << setprecision(5) << Closest_dist(P, stp, n, pnt1, pnt2) << endl;
            delete[] stp;

            index = 0;
            count = 0;
        }
    }
    return 0;
}