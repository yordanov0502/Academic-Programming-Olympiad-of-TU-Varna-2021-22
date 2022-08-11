//Chast ot algorituma e suglasuvan s obqsneniqta
//po tozi vid zadachi("Bratska podqlba") ot knigata Programirane=++Algoritmi;
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 1000 // maksimalen broj elementi na mnojestvoto 
#define MAXVALUE 9999 //Maksimalna vuzmojna stoinost na vseki element
bool can[MAX * MAXVALUE + 1]; /* Masiv za sumi koito proverqva dali opredelenata suma ve4e e bila poluchena */

using namespace std;


int main() {

    for (int testove = 0; testove < 12; testove++)
    {
        int N = 0;//nevuzmojna stojnost
        cin >> N;//broj elementi na mnojestvoto

        if (N == 0) { break; } //uslovie za prekratqvane na programata


        else {

            int* S = new int[N]; //mnojestvo S sus N na broj elementi
            long long tS = 0; //suma(teglo) ot elementite na mnojestvoto S

            for (int i = 0; i < N; i++)
            {
                do { cin >> S[i]; } while (S[i] < 1 || S[i] >= 10000);
                tS += S[i]; //presmqta sumata(tegloto) ot elementite na mnojestvoto S
            }

            //Zadavam na purvona4alni stoinosti na buleviq masiv, koito shte proverqva sumite
            for (int i = 0; i <= tS; i++)
            {
                if (i == 0) { can[i] = 1; }

                else { can[i] = 0; }
            }


            //Otkrivam vuzmojnite sumi ot stoinostite na elementite na mnjestvoto S
            for (int i = 0; i < N; i++)
                for (int j = tS; j + 1 > 0; j--)
                    if (can[j])
                    {
                        can[j + S[i]] = 1;
                    }


            
            for (int i = tS / 2; i > 1; i--)
            {
                if (can[i]) 
                { 
                     
                    cout << i << endl;
                  

                break;
                }
            }

        }

    }

    return 0;
}
