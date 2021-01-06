/**
 * @file ivb.multiple.left.rotation
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday January 05 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi solve(vi a, vi b) {
  int n = b.size(), m = a.size();
  vvi ans(n);

  for (int i = 0; i < n; ++i) {
    int s = b[i] % m;
    for (int j = s; j < m + s; ++j)
      ans[i].push_back(a[j >= m ? j - m : j]);
  }

  return ans;
}
