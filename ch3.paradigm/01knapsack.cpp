//
// Created by Touhid Alam on 3/30/20.
//

#include <algorithm>
#include <cstdio>
#include <vector>
#include <unordered_set>

int n = 10, v[] = {92, 57, 49, 68, 60, 43, 67, 84, 87, 72}, w[] = {23, 31, 29, 44, 53, 38, 63, 85, 89, 82};
int memo[10][165];

std::unordered_set<int> selection;

int ks(int i, int rw) {
    if (rw == 0 || i == 9) return 0;
    else if (w[i] > rw) return ks(i + 1, rw);
    else if (memo[i][rw] != -1) return memo[i][rw];
    int c1 = ks(i + 1, rw), c2 = v[i] + ks(i + 1, rw - w[i]);

    if (c2 < c1) { ;
    } else {
        selection.insert(i);
    }
    return memo[i][rw] = std::max(c1, c2);
}

int main() {
    std::memset(memo, -1, sizeof(memo));
    printf("%d\tselection: {", ks(0, 165));

    for (int id: selection) {
        printf("%d, ", v[id]);
    }
    printf("}");
    return 0;
}