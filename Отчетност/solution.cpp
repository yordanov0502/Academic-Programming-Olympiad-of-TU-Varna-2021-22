#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>        
#include <sstream>      
#include <unordered_map>

using namespace std;

unordered_map<string, int> umap;

bool comparator(string a, string b)
{
    return a < b;
}

void sortOVCE(string str)
{
    istringstream ss(str);

    string sentence;
    int count = 0;
    string array[3];

    while (ss >> array[count])
    {
      count++;
    }

    sort(array, array + 3, comparator);
    sentence = array[0] + " " + array[1] + " " + array[2];

    // check if key `sentence` exists in the map or not
    std::unordered_map<string, int>::iterator it = umap.find(sentence);

    // key already present on the map
    if (it != umap.end()) {
        it->second++;    // increment map's value for key `sentence`
    }
    // key not found
    else { umap.insert(make_pair(sentence, 1)); }
}

int main() {
   
    int N; //Chasove

    while (1)
    {
        cin >> N;
        if (N == 0) { break; }

        else {
            string* OVCE = new string[N];
            cin.ignore();

            for (int i = 0; i < N; i++)
            {
                getline(cin, OVCE[i]);
                sortOVCE(OVCE[i]);
            }

            int max = 1;
            for (auto pair : umap)
            {
                if (pair.second > max) { max = pair.second;}
            }
            cout << max << endl;
            umap.erase(umap.begin(), umap.end());
            delete[] OVCE;
        }
    }
    return 0;
}
