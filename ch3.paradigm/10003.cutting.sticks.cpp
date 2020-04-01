#include <bits/stdc++.h>

using namespace std;

#define INF 1e5 + 7

int c[55], memo[55][55];

int cut(int l, int r) {
    if (r - 1 == l) return 0;

    if (memo[l][r] != -1) return memo[l][r];

    int best = INF;

    for (int i = l + 1; i < r; ++i) {
        best = min(best, cut(l, i) + cut(i, r) + c[r] - c[l]);
    }

    return memo[l][r] = best;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int l, n;

    while (cin >> l, l) {
        cin >> n;

        memset(c, 0, sizeof c);
        memset(memo, -1, sizeof memo);

        for (int i = 0; i < n; ++i) {
            cin >> c[i + 1];
        }

        c[n + 1] = l;
        cout << "The minimum cutting is " << cut(0, n + 1) << '.' << endl;
    }

    return 0;
}
