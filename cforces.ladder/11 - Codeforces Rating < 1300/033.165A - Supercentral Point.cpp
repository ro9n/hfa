/**
 * @file 033.165A - Supercentral Point.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sat Jun 20 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define INF 1e5

typedef pair<int, int> ii;

int main() {
  int n, s = 0;
  cin >> n;

  vector<ii> v;
  map<int, ii> xx, yy;  // x -> {miny, maxy}, y -> {minx, maxx}

  while (n--) {
    int x, y;
    cin >> x >> y;
    v.eb(mp(x, y));

    if (!xx.count(x)) xx[x] = {INF, -INF};
    if (!yy.count(y)) yy[y] = {INF, -INF};

    xx[x].ff = min(xx[x].ff, y);
    xx[x].ss = max(xx[x].ss, y);
    yy[y].ff = min(yy[y].ff, x);
    yy[y].ss = max(yy[y].ss, x);
  }

  for (auto p : v) {
    int x = p.first, y = p.second;
    // right left lower upper
    if (x >= yy[y].ss) continue;
    if (x <= yy[y].ff) continue;
    if (y >= xx[x].ss) continue;
    if (y <= xx[x].ff) continue;

    ++s;
  }

  cout << s << endl;
  return 0;
}