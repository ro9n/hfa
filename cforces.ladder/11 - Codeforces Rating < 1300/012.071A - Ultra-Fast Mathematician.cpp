/**
 * @file 012.071A - Ultra-Fast Mathematician.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Mon Jun 15 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    string x, y;
    getline(cin, x);
    getline(cin, y);

    for (int i = 0; i < x.size(); ++i) {
        if (x[i] != y[i]) cout << '1';
        else cout << '0';
    }

    cout << endl;
    return 0;
}