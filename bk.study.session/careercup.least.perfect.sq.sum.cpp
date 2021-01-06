/**
 * @file careercup.least.perfect.sq.sum
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wednesday January 06 2021
 *
 * @brief Given number N, Find the least number of perfect square number sum needed
 *  to get N. 
 * 
 * Example : 
 * n=5 (4+1) i.e. 2 
 * n=7 (4+1+1+1) i.e. 4 
 * n=12 (4+4+4) i.e 3 
 * n=20 (16+4) i.e. 2
 */

#include <bits/stdc++.h>

using namespace std;

// k√k coin change
int solve(int k) {
  int dp[k + 1];
  dp[0] = 0;

  for (int i = 1; i <= k; ++i) {
    dp[i] = i;
    for (int j = 1; j <= sqrt(i); ++j) {
      dp[i] = min(dp[i], 1 + dp[i - j * j]);
    }
  }

  return dp[k];
}

int main() {
  cout << "5→" << solve(5) << endl
       << "7→" << solve(7) << endl
       << "12→" << solve(12) << endl
       << "20→" << solve(20);
  return 0;
}
