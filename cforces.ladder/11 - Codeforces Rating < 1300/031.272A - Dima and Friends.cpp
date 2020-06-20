/**
 * @file 031.272A - Dima and Friends.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thu Jun 18 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, s = 0, w = 0; cin >> n;
    for (int i = 0; i < n; ++i) {
        int k; cin >> k; s += k;
    }

    for (int i = 1; i <= 5; ++i) 
        if((s + i) % (n + 1) != 1) ++w;
    
    cout << w << endl;

    return 0;
}