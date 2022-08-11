#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip> //std::fixed and std::setprecision(...)
using namespace std;


int main() {
   
    int T; //broj testove
    cin >> T;

    while (T < 1 || T > 50) //Proverka dali sa spazeni ograni4eniqta
    {
        cin >> T;
    }

    for (int g = 0; g < T; g++)                    
    {
        int N;//broj korabi
        cin >> N;

        while (N < 1 || N > 1000) //Proverka dali sa spazeni ograni4eniqta
        {
            cin >> N;
        }


        int* X = new int[N];
        int* Y = new int[N];
        int* DX = new int[N];
        int* DY = new int[N];
        int* DR = new int[N];

        double* time = new double[N];

        for (int i = 0; i < N; i++)
        {
            cin >> X[i]; cin >> Y[i]; cin >> DX[i]; cin >> DY[i];cin >> DR[i]; //danni za korab i purvona4alen snarqd
        }

        int LX1, LY1, LX2, LY2;

        cin >> LX1 >> LY1 >> LX2 >> LY2;

        

        double a, b, c;
        a = (LY2 - LY1) / sqrt((LY2 - LY1) * (LY2 - LY1) + (LX1 - LX2) * (LX1 - LX2));
        b = (LX1 - LX2) / sqrt((LY2 - LY1) * (LY2 - LY1) + (LX1 - LX2) * (LX1 - LX2));
        c = -(a * LX1 + b * LY1);


        
        int n = 3; //br cifri sled zapetaq
        int error = -909; //chislo koeto da prisvoi na time[i] ako znamenatelq e < 0   ili   time[i] < 0 za da moje 
                            //posle da tursi tova chislo sred vsichki time[i] za vseki korab po otdelno i ako vsichki
                            //time[i] za opredelen test sa s takava stoinost to da otpechata NEVER vednuj

        for (int i = 0; i < N; i++)
        {
           

            if ((a * X[i] + b * Y[i] + c) > 0) 
            { 
                
                if ((DR[i] - a * DX[i] - b * DY[i]) == 0) { time[i] = error; } 
                
                else if (((a * X[i] + b * Y[i] + c) / (DR[i] - a * DX[i] - b * DY[i])) < 0) { time[i] = error; }
                    
                else { time[i] = (a * X[i] + b * Y[i] + c) / (DR[i] - a * DX[i] - b * DY[i]); }
            }



            if ((a * X[i] + b * Y[i] + c) < 0) 
            { 
                
                if ((DR[i] + a * DX[i] + b * DY[i]) == 0) { time[i] = error; }

                else if ((-(a * X[i] + b * Y[i] + c) / (DR[i] + a * DX[i] + b * DY[i])) < 0) { time[i] = error; }
                
                else { time[i] = -(a * X[i] + b * Y[i] + c) / (DR[i] + a * DX[i] + b * DY[i]); }
            }


        }

        int counter = 0; //broq4 na greshki
        int index = 0;//index na minimalna stoinost za time
        double min = 9999999999999;//purvona4alna minimalna stoinost za time

        for (int i = 0; i < N; i++) 
        {
            if (time[i] != error && time[i] < min)
            {
                min = time[i]; index = i;
            }

            if (time[i] == error) { counter++; }
        }


        if (counter == N) { cout << "NEVER" << endl; } 
        //Ako counter e raven na broq korabi za daden test to vsichki time[i] za dadeniq test
        //sa <0 ili znamenatelq im e =0 spored programnata logika koqto sum opisal po gore vuv dvata for cikula
                                                       

        else { std::cout << std::fixed << std::setprecision(n) << time[index] << std::endl; }
        //otpe4atva nai malkiq time[i] za opredeleniq test
        
   

    }

    return 0;
}
