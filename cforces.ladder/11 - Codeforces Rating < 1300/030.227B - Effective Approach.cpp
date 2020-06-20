/**
 * @file 030.227B - Effective Approach.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thu Jun 18 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

int main() {
    int n, d[N], m, q[N];
    long long c1 = 0, c2 = 0;
    cin >> n;
    
    map<int, int> M;

    for(int i = 0; i < n; ++i) {
        cin >> d[i];
        M[d[i]] = i;
    }

    cin >> m;
    for(int i = 0; i < m; ++i) {
        cin >> q[i];
    }


    for (int j = 0; j < m; ++j){
        c1 += M[q[j]] + 1;
        c2 += n - 1 - M[q[j]] + 1;
    }

    cout << c1 << ' ' << c2 << endl;
    return 0;
}