// TEMA: Rolling Hash

//Resursi:
// https://www.informatika.bg/lectures/hashing
// https://en.wikipedia.org/wiki/Rolling_hash
// https://www.geeksforgeeks.org/string-hashing-using-polynomial-rolling-hash-function/
// https://cp-algorithms.com/string/string-hashing.html

// Procetete teoriyata i
// Razgledjate vnimatelno reshenieto na tekustata zadaca

// Primerna reshenie na zadacata na tema Rollong Hash:
// Izpolzuva dwoicno tyrsene za da fiksira dylzinata na tyrsenija powtarjast se substring.
// S Rollong Hash otkriva dali ima powtaryast se pod-string s dylzina fixed_length i ot
// vsicki powtaryasti se vrysta naj-malkiya po leksikogrfski red.



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int MAX_STR_LEN = 100001;

int BASE1 = 1000000007;
int BASE2 = 1000000009;

int POWERED_BASE1[MAX_STR_LEN];
int POWERED_BASE2[MAX_STR_LEN];

typedef unsigned long long ull;

void init() {
    int curr_pow1 = 1;
    int curr_pow2 = 1;
    for (int i = 0; i < MAX_STR_LEN; i++) {
        POWERED_BASE1[i] = curr_pow1;
        POWERED_BASE2[i] = curr_pow2;
        curr_pow1 = curr_pow1 * BASE1;
        curr_pow2 = curr_pow2 * BASE2;
    }

}

bool substr_found(string& s, int fixed_length, string& res_str) {

    int hash1 = 0;
    int hash2 = 0;
    unordered_map<ull, int> hash_map;
    res_str = (char)('Z' + 1);
    bool res = false;
    for (int i = 0; i < s.size(); i++) {
        if (i < fixed_length) {
            hash1 = hash1 * BASE1 + s[i];
            hash2 = hash2 * BASE2 + s[i];
            if (i < fixed_length - 1)
                continue;
        }
        else {
            hash1 = hash1 * BASE1 + s[i] - s[i - fixed_length] * POWERED_BASE1[fixed_length];
            hash2 = hash2 * BASE2 + s[i] - s[i - fixed_length] * POWERED_BASE2[fixed_length];
        }
        ull key = ((ull)hash1 << 32) + hash2;
        auto it = hash_map.find(key);

        if (it != hash_map.end()) {
            res = true;
            string curr_str = s.substr(i - fixed_length + 1, fixed_length);
            if (curr_str < res_str)
                res_str = curr_str;
        }

        hash_map[key] = i;
    }

    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    init();

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        int len = s.size();

        int left_pos = 0;
        int right_pos = len;

        string res_str = "";
        while (left_pos < right_pos) {
            int mid_pos = (left_pos + right_pos + 1) / 2;

            string res_str2;
            bool res = substr_found(s, mid_pos, res_str2);
            if (res) {
                left_pos = mid_pos;
                res_str = res_str2;
            }
            else {
                right_pos = mid_pos - 1;
            }
        }
        cout << res_str << endl;
    }
    return 0;
}