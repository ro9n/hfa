/**
 * @file 032.450A - Jzzhu and Children.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Fri Jun 19 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;

int main() {
    int n, m; cin >> n >> m;
    queue <ii> q;
    
    for (int i = 0; i < n; ++i) {
        int k; cin >> k; q.push({i + 1, k});
    }

    while (q.size() > 1) {
        ii f = q.front(); q.pop();
        if (f.second <= m) continue;
        q.push({f.first, f.second - m});
    }

    cout << q.front().first << endl;
    return 0;
}