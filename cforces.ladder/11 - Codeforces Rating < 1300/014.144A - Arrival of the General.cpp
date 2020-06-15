/**
 * @file 014.144A - Arrival of the General.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Mon Jun 15 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, h[100], mx = 0, mn = 101, l, r, s;

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> h[i];
    // left most l: taller
    if (mx < h[i]) {
      mx = h[i];
      l = i;
    }
    // right most r: shorter
    if (mn >= h[i]) {
      mn = h[i];
      r = i;
    }
  }

  if (n == 2)
    s = h[0] < h[1];
  else {
      s = l + (n - 1 - r);
      if (r < l) s--;
  }

  cout << s << endl;
  return 0;
}