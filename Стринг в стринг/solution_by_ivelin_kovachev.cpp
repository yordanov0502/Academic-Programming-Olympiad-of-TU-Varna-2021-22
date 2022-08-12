#include <cmath>
#include <cstdio>
#include <vector>
#include <string>

#include <iostream>
#include <algorithm>
using namespace std;

int BASE = 1000000007;
int BASE_POWERED_ON_SEARCHED_STRING_LENGTH;

void calc_BASE_POWERED_ON_SEARCHED_STRING_LENGTH(int n)
{
    BASE_POWERED_ON_SEARCHED_STRING_LENGTH = 1;
    for (int i = 0; i < n; i++)
       BASE_POWERED_ON_SEARCHED_STRING_LENGTH *= BASE; 
}

// If you have to search for strings with different lengths 
// you should pre-calculate an array: 
// int BASES_POWERED_ON_ALL_SEARCHED_STRINGS_LENGTHS[MAX_SEARCHED_STRING_LENGTH+1]; 

// void BASES_POWERED_ON_ALL_SEARCHED_STRINGS_LENGTHS(int n)
// {
//     int curr = 1;
//     for (int i = 0; i <= n; i++) {
//        BASES_POWERED_ON_ALL_SEARCHED_STRINGS_LENGTHS[i] = curr;	
//        curr *= BASE; 
//     }
// }

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    calc_BASE_POWERED_ON_SEARCHED_STRING_LENGTH(s1.length()); 

    unsigned int hash1 = 0;
    // Calculating the hash for the whole string s1
    for (int i = 0; i < s1.length(); i++)
        hash1 = hash1 * BASE + s1[i]; // We are using implicitly Module = 2^32, because
        //the processor is performing module 2^32 implicitly on every arithmetic operation.
        //The result is the same as this:
        //hash1 = ((unsigned long long)hash1 * BASE + s2[i]) % ((unsugned long long)1<<32)
        // But  hash1 = hash1 * BASE + s2[i]; is much faster if the compiler doesn't optimizes the above code
     
    int count = 0;    
    unsigned int hash2 = 0;
    for (int i = 0; i < s2.length(); i++) {
        hash2 = hash2 * BASE + s2[i]; 
        
        if (i >= s1.length())
            hash2 -= s2[i - s1.length()] * BASE_POWERED_ON_SEARCHED_STRING_LENGTH; // calculating the hash for s2.substr(i - s1.length() + 1, s1.length()) from the hash of s2.substr(i - s1.length(), s1.length() + 1)
        if (hash1 == hash2)
            count++;
    }
    cout << count;
    return 0;
}