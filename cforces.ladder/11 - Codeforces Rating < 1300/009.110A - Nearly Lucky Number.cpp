/**
 * @file 009.110A - Nearly Lucky Number.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Mon Jun 15 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int c = 0;

    for(auto ch: s) {
        if (ch == '4' || ch == '7') ++c;
    }

    if (c == 4 || c == 7) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}