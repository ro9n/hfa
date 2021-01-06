/**
 * @file scc
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wednesday January 06 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define WHITE 0
#define GREY  1

vector<int> color, d, h, s;
vector<vector<int>> g;
vector<vector<int>> sccs;
int c;
void scc_tarjan(int u) {
  d[u] = h[u] = ++c;

  s.push_back(u), color[u] = GREY;

  for (auto v : g[u]) {
    if (color[v] == WHITE) scc_tarjan(v);
    if (color[v] > WHITE) d[u] = min(d[u], d[v]);
  }

  if (d[u] == h[u]) {
    // root
    vector<int> tmp;
    while (1) {
      int v = s.back();
      s.pop_back();
      tmp.push_back(v), color[v] = WHITE;
      if (u == v) {
        sccs.push_back(tmp);
        break;
      }
    }
  }
}

int main() {
  g = {
      {1},
      {3},
      {1},
      {2, 4},
      {5},
      {7},
      {4},
      {6}};

  const int INF = 1e9 + 7;
  int n = g.size();
  color.assign(n, WHITE);
  h.assign(n, 0);
  d.assign(n, INF);
  c = 0;
  scc_tarjan(0);
  for (auto scc : sccs) {
    cout << '{';
    for (auto v : scc) cout << v << ',';
    cout << '}';
  }

  return 0;
}
