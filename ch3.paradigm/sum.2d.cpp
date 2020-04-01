//
// Created by Touhid Alam on 3/26/20.
//

#include <cstdio>
#include <algorithm>

int main() {
    int n(0);
    scanf("%d", &n);

    int v[n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > 0) v[i][j] += v[i - 1][j];
            if (j > 0) v[i][j] += v[i][j - 1];
            if (i > 0 && j > 0) v[i][j] -= v[i - 1][j - 1];
        }
    }

    int best = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = i; k < n; ++k) {
                for (int l = 0; l < n; ++l) {
                    int sum(v[k][l]);
                    if (i > 0) sum -= v[i - 1][l];
                    if (j > 0) sum -= v[k][j - 1];
                    if (i > 0 && j > 0) sum += v[i - 1][j - 1];
                    best = std::max(sum, best);
                }
            }
        }
    }
}