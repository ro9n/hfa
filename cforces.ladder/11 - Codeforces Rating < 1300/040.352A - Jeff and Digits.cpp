/**
 * @file 040.352A - Jeff and Digits.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sun Jun 21 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int zs = 0, fs = 0, n; cin >> n; while(n--) {
        int k; cin >> k;
        if (k == 5) ++fs; else ++ zs;
    }

    if (!zs){ cout << -1 << endl; return 0;} 

    while (fs > 0 && (5 * fs) % 9) --fs;
    
    if(fs <= 0) {cout << 0 << endl; return 0;}

    string s; while(fs--) {
        s += to_string(5);
    } while(zs--) {
        s += to_string(0);
    }
    cout << s << endl;
    return 0;
}