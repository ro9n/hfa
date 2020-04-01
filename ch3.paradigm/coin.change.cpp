#include <algorithm>
#include <cstdio>

#define INF 1e4 + 7

int v = 10, n = 3, c[] = {1, 5, 10};

int choose(int rv) {
    if (rv == 0)
        return 0;
    else if (rv < 0)
        return INF;
    else {
        int best = INF;
        for (int i = 0; i < n; ++i) {
            best = 1 + std::min(choose(rv - c[i]), best);
        }
        return best;
    }
}

int main() {
    printf("%d", choose(v));
}