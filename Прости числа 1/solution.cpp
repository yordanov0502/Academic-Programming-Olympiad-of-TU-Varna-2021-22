#include <stdio.h>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string>
#include <cwctype>
#include <clocale>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXN 100000000

int t, a, b;
int lp[MAXN + 100];
vector<int> pr;
vector<int>::iterator low, up;
char q;
char c[100];

void precompute()
{
    for (int i = 2; i < MAXN; i++)
    {
        if (lp[i] == 0) 
        {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < MAXN; j++)
            lp[i * pr[j]] = pr[j];
    }
}

inline bool isPrime(int &a)
{
    return binary_search(pr.begin(), pr.end(), a) ? 1 : 0;
}

int main()
{
    precompute();

    while(true)
    {
        cin>>q;
        q = towlower(q);
        
        switch(q)
        {
            case 'a' :
                cin>>a>>b;
                low = lower_bound (pr.begin(), pr.end(), a);
                up = upper_bound (pr.begin(), pr.end(), b); 
                cout<<(int)(up - low)<<endl;
                break;
                
            case 'b' :
                cin>>a;
                cout<<lp[a]<<endl;
                break;
                
            case 'c' :
                cin>>a;
                cout<<isPrime(a)<<endl;
                break;
                
            case 'd' :
                cin>>c;
                reverse(c, c + strlen(c));
                a = atoi(c);
                cout<<isPrime(a)<<endl;
                break;
                
            case 'e' :
                cin>>a;
                if(isPrime(a)) cout<<a<<endl;
                
                else
                {
                    low = lower_bound (pr.begin(), pr.end(), a);
                    up = upper_bound (pr.begin(), pr.end(), a); 
                    --low;
                    int distToLow = a - *low;
                    if(up == pr.end())
                        --up;

                    int distToUp = *up - a;
                    if(distToLow == distToUp)
                        cout<<*low<<" "<<*up<<endl;
                    else {
                        if(distToLow < distToUp) cout<<*low<<endl;
                        else cout<<*up<<endl;   
                    }
                }
                break;
                
            case 'f' :
                cin>>a;
                low = lower_bound (pr.begin(), pr.end(), a);
                cout<<low - pr.begin()<<endl;
                break;
            case 'q' :
                
                return 0;
        }
    }

    return 0;
}