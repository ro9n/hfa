//
// Created by Touhid Alam on 3/29/20.
//

#include <algorithm>
#include <cstdio>
#include <climits>
#include "lis.h"

int v[] = {-7, 10, 9, 2, 3, 8, 8, 1};

int main() {
    int memo[8], best = INT_MIN, p[8], best_index;
    memo[0] = 1;
    for (int i = 1; i < 8; ++i) {
        for (int j = 0; j < i; ++j) {
            if (v[j] < v[i]) {
                p[i] = j;
                memo[i] = std::max(memo[i], memo[j] + 1);
            }
            if (best < memo[i]) best_index = i;
            best = std::max(best, memo[i]);
        }
    }

    printf("%d", best_index);
    while (p[best_index] != 0) {
        printf("<-%d", p[best_index]);
        best_index = p[best_index];
    }
    printf("<-0\n");
    printf("%d", best);

}