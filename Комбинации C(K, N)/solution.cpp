#include <iostream>
using namespace std;

void Combinations(char array[], int requiredLength, int s, int currLength, bool check[], int l)
{
    if (currLength > requiredLength) { return; }

    else if (currLength == requiredLength)
    {
        for (int i = 0; i < l; i++) 
        {
            if (check[i] == true) { cout << array[i]; }
        }
        cout << "\n";
        return;
    }

    if (s == l) { return; }

    check[s] = true;
    Combinations(array, requiredLength, s + 1, currLength + 1, check, l);
    check[s] = false;
    Combinations(array, requiredLength, s + 1, currLength, check, l);
}

int main() {

    int n,k;
    cin >> n;
    cin >> k;
   
    bool* check = new bool[n];
    char* array = new char[n];

    for (int i = 0; i < n; i++) 
    {
        array[i] = 'A' + i;
        check[i] = false;
    }
  
    Combinations(array, k, 0, 0, check, n);
    
    return 0;
}
