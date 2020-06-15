/**
 * @file 015.22B - Drinks.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tue Jun 16 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, s = 0;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> k;
        s += k;
    }
    cout << fixed << setprecision(12) << (double) s / n << endl;
    return 0;
}