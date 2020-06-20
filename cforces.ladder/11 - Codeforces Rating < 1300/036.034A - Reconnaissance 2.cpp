/**
 * @file 036.034A - Reconnaissance 2.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sat Jun 20 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, f, h[100], mn = 1000, best; cin >> n;

  for (int i = 0; i < n; ++i) cin >> h[i];

  f = h[0];
  for (int i = 1; i < n; ++i) h[i - 1] = abs(h[i] - h[i - 1]);
  h[n - 1] = abs(h[n - 1] - f);

  for (int i = 0; i < n; ++i) {
      if (h[i] < mn) {
          mn = h[i];
          best = i;
      }
  }

  cout << best + 1 << ' ';

  if (best == n - 1) cout << 1 << endl;
  else cout << best + 2 << endl;
  return 0;
}