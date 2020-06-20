/**
 * @file 026.133A - HQ9+.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thu Jun 18 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    for(int i = 0; i < s.size(); ++i) {
        if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9') {
            cout << "YES" << endl; return 0;
        }
    }
    cout << "NO" << endl; return 0;
    return 0;
}