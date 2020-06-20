/**
 * @file 025.151A - Soft Drinking.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thu Jun 18 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;

  int dd = (k * l / nl), ll = c * d, ss = p / np;
  cout << min({dd, ll, ss}) / n << endl;
  return 0;
}