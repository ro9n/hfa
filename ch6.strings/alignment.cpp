#include <bits/stdc++.h>
// #include <iostream>
// #include <string>

using namespace std;

#define INF 1e6

// const int MATCH = 2, MISMATCH = -1, ADD = -1, REMOVE = -1;
// LCS
const int MATCH = 1, MISMATCH = -INF, ADD = 0, REMOVE = 0;

// Needleman Wunsnch's algorithm
// A[0...i], B[0...j]
int main() {
    string a = "bl", b = "yby";

    int n = a.size(), m = b.size(), memo[n + 1][m + 1];

    memset(memo, 0, sizeof memo);

    for (int i = 1; i <= n; ++i) memo[i][0] = -i;
    for (int j = 1; j <= m; ++j) memo[0][j] = -j;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            memo[i][j] = max(memo[i][j], memo[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? MATCH : MISMATCH));
            memo[i][j] = max(memo[i][j], memo[i - 1][j] + REMOVE);
            memo[i][j] = max(memo[i][j], memo[i][j - 1] + ADD);
        }
    }

    // print memo
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++)
            cout << setw(3) << memo[i][j];
        cout << endl;
    }

    cout << memo[n][m] << endl;
}