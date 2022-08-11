#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int W, N;
vector<pair<string, int> > dict;

bool match(string& pref, string& word) 
{
    if (pref.size() > word.size()) return false;

    return word.substr(0, pref.size()) == pref;
}

int main() 
{
    while(true)
    {
        string line;
        getline (cin, line, '\n');
        
        if(line.empty()) {getline (cin, line, '\n');}

        if(line == "exit") {break;}
        
        istringstream iss(line);
        iss >> W >> N;
        
        dict.clear();

        for (int i = 0; i < W; i++) 
        {
            string s;
            cin >> s;
            dict.push_back(make_pair(s, i));
        }

        sort(dict.begin(), dict.end());

        for (int i = 0; i < N; i++)
        {
            int k;
            string pref;
            cin >> k >> pref;
            k--;
            int pos = lower_bound(dict.begin(), dict.end(), make_pair(pref, 0)) - dict.begin();

            
            int poss = pos + k;
            if (poss < dict.size() && match(pref, dict[poss].first)) 
            {cout << dict[poss].second + 1 << '\n';}
            
            else    {cout << -1 << '\n';}
        }
    }
    return 0;
}