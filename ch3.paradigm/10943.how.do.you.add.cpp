#include <cstdio>
#include <cstring>

#define MOD 1e6

int memo[101][101];

int ways(int n, int k) {
    if (k == 1)
        return 1;
    else if (memo[n][k])
        return memo[n][k];
    int w = 0;
    for (int i = 0; i <= n; ++i) {
        w += ways(n - i, k - 1) % (int)MOD;
    }
    return memo[n][k] = (int)w % (int)MOD;
}

int main() {
    int n = 0, k = 0;

    while (scanf("%d %d", &n, &k), n || k) {
        memset(memo, 0, sizeof(memo));
        printf("%d\n", ways(n, k) % (int)MOD);
    }

    return 0;
}