/**
 * @file 028.231A - Team.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thu Jun 18 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i = 0; cin >> n;
    while(n--) {
        int p, v, t;
        cin >> p >> v >> t;
        if (p + v + t > 1) ++i;
    }

    cout << i << endl;
    return 0;
}