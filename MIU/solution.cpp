#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string add_U(string MIU) 
{
    if (MIU[MIU.length() - 1] == 'I')
    MIU = MIU + 'U';
    return MIU;
}

string add_Mx(string MIU)
{
   if (MIU[0] == 'M')
   MIU = MIU + MIU.substr(1, MIU.length() - 1);
   return MIU;
}

string replace_III_U(string MIU) 
{
    size_t found;
    found = MIU.find("III");
    while (found != string::npos) 
    {
        MIU.replace(found, 3, "U");
        found = MIU.find("III");
    }
    return MIU;
}

string remove_UU(string MIU) 
{
    size_t found;
    found = MIU.find("UU");
    while (found != string::npos) 
    {
        MIU.erase(found, 2);
        found = MIU.rfind("UU");
    }
    return MIU;
}

int main() 
{
    string input;

    while (getline(cin, input))
    {
        string miu = "MI";

        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == 'A') { miu = add_U(miu); }

            else if (input[i] == 'B') { miu = add_Mx(miu); }

            else if (input[i] == 'C') { miu = replace_III_U(miu); }

            else { miu = remove_UU(miu); }
        }
        cout << miu << endl;
    }
    return 0;
}