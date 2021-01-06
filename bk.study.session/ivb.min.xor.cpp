/**
 * @file ivb.min.xor
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday January 05 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> A) {
  int n = A.size(), best = INT_MAX;

  sort(A.begin(), A.end());

  for(int i = 1; i < n; ++i) {
    best = min(best, A[i] ^ A[i - 1]);
  }
  return best;
}
