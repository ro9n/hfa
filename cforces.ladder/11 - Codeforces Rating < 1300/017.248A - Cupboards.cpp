/**
 * @file 017.248A - Cupboards.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tue Jun 16 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, lon = 0, lof = 0, ron = 0, rof = 0, ans = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    if (l)
      ++lon;
    else
      ++lof;
    if (r)
      ++ron;
    else
      ++rof;
  }

  if (lon < lof)
    ans += lon;
  else
    ans += lof;

  if (ron < rof)
    ans += ron;
  else
    ans += rof;

  cout << ans << endl;
  return 0;
}