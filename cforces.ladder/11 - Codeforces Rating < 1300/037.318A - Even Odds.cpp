/**
 * @file 037.318A - Even Odds.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sat Jun 20 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n, k, r; cin >> n >> k;
    ll lastodd = n / 2;
    
    if (n & 1) ++lastodd;

    if (k <= lastodd) {
        // odd
        r = 2 * k - 1;
    } else {
        // even
        k -= lastodd;
        r = 2 * k;
    }

    cout << r << endl;
    return 0;
}