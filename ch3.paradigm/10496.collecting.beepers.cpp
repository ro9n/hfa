#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

// karel + max 10 beepers
#define N 11

int n, x[N], y[N], d[N][N], memo[N][1 << N];

/**
 * i index of position
 * m bit mask
 **/
int tsp(int i, int m) {
    if (m == (1 << (n + 1)) - 1)
        return d[i][0];
    else if (memo[i][m] != -1)
        return memo[i][m];

    int c = 1e9 + 7;  // cost

    for (int j = 0; j <= n; ++j) {
        if (j != i && !(m & (1 << j))) {
            c = min(c, d[i][j] + tsp(j, m | (1 << j)));
        }
    }

    return memo[i][m] = c;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int w, h;
        cin >> w >> h >> x[0] >> y[0] >> n;

        // karel at 0
        for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];

        /// create manhattan distance table: cost of moving from a to b
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                d[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            }
        }

        memset(memo, -1, sizeof memo);
        cout << "The shortest path has length " << tsp(0, 1) << endl;
    }

    return 0;
}