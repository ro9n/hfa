/**
 * @file 019.116A - Tram.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wed Jun 17 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, c = 0, mx = 0; cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;
        c += (b - a);
        mx = max(mx, c);
    }

    cout << mx << endl;
    return 0;
}