/**
 * @file 034.139A - Petr and Book.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sat Jun 20 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p[7]; cin >> n;
    for(int i = 0; i < 7; ++i) cin >> p[i];

    int i = 0;
    while (n > p[i]) {
        n -= p[i++];
        if (i == 7) i = 0;
    }

    cout << i + 1 << endl;
    return 0;
}