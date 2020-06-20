/**
 * @file 027.112A - Petya and Strings.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thu Jun 18 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1); getline(cin, s2);

    int n = s1.size();

    for(int i = 0; i < n; ++i) {
        int cs1 = tolower(s1[i]) - 'a', cs2 = tolower(s2[i]) - 'a';
        if (cs1 == cs2) continue;
        else if (cs1 < cs2) {
            cout << -1 << endl; return 0;
        } else {
            cout << 1 << endl; return 0;
        }
    }
    
    cout << 0 << endl;

    return 0;
}