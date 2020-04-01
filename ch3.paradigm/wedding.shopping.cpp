#include <cstdio>
#include <cstring>
#include <algorithm>
/**
 One of our best friends is getting married and we all are nervous because he is the first of us who is doing something
 similar. In fact, we have never assisted to a wedding, so we have no clothes or accessories, and to solve the problem
 we are going to a famous department store of our city to buy all we need: a shirt, a belt, some shoes, a tie, etc.

 We are offered different models for each class of garment (for example, three shirts, two belts, four shoes, ...). We
 have to buy one model of each class of garment, and just one.

 As our budget is limited, we cannot spend more money than it, but we want to spend the maximum  possible. It’s possible
 that we cannot buy one model of each class of garment due to the short amount of money we have.

 Input
 The first line of the input contains an integer,N, indicating the number of test cases. For each test  case, some lines
 appear, the first one contains two integers, M and C, separated by blanks (1 ≤ M ≤ 200,  and 1 ≤ C ≤ 20), where M is
 the available amount of money and C is the number of garments you have to buy. Following  this line, there are C lines,
 each one with some integers separated by blanks; in each of these lines the first integer, K (1 ≤ K ≤ 20), indicates
 the number of different models for each garment and it is followed by K integers indicating the price of each model of
 that garment.

 Output
 For each test case, the output should consist of one integer indicating the maximum amount of money necessary to buy
 one element of each garment without exceeding the initial amount of money. If there is no solution, you must print ‘no
 solution’.

 Sample Input
3
100 4
3 8 6 4
2 5 10
4 1 3 3 7
4 50 14 23 8
20 3
3 4 6 8
2 5 10
4 1 3 5 5
5 3
3 6 4 8
2 10 6
4 7 3 1 7

 Sample Output
75
19
no solution
 */

#define INF 1e4+7
using namespace std;
int N, M, C, price[25][25], memo[25][210]; // (garment, model), (garment, money)

int shop(int g, int m) {
    if (m < 0) return -INF;
    if (g == C) return M - m;

    int &ans = memo[g][m];
    if (ans != -1) return ans;

    for (int k = 1; k <= price[g][0]; ++k) {
        ans = max(ans, shop(g + 1, m - price[g][k]));
    }

    return ans;
}

int wedding_shopping() {
    scanf("%d", &N);

    while (N--) {
        // different test cases
        scanf("%d %d", &M, &C);

        memset(price, 0, sizeof price);
        for (int c = 0; c < C; ++c) {
            scanf("%d", &price[c][0]);
            for (int k = 1; k <= price[c][0]; ++k) {
                scanf("%d", &price[c][k]);
            }
        }

        memset(memo, -1, sizeof memo);
        int ans = shop(0, M);
        if (ans < 0) printf("no solution\n");
        else printf("%d\n", ans);
    }

}
