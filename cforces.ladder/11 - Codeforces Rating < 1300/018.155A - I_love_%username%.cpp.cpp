/**
 * @file 018.155A - I_love_%username%.cpp.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tue Jun 16 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, best = -1, worst, amz = 0; cin >> n;

    while (n--) {
        int k; cin >> k;
        if (best == -1) best = worst = k;
        else if (k > best || k < worst) best = max(best, k), worst = min(worst, k), ++amz;
    }

    cout << amz << endl;

    return 0;
}