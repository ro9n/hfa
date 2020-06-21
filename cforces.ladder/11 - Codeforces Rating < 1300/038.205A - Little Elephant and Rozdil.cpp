/**
 * @file 038.205A - Little Elephant and Rozdil.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sat Jun 20 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
int main() {
  int n, d[N], mn = 1e9;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
    mn = min(mn, d[i]);
  }

  int best, f = 0;
  for (int i = 0; i < n; ++i) {
    if (d[i] == mn) ++f, best = i;
  }

  if (f > 1) cout << "Still Rozdil" << endl;
  else cout << best + 1 << endl;

  return 0;
}

