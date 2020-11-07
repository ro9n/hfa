/**
 * @file scc.directed.tarjan
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday October 25 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

enum { UNVISITED };
vi dfs_num, dfs_low, s, vis;
vi g[8] = {
    {1},     // 0
    {3},     // 1
    {1},     // 2
    {2, 4},  // 3
    {5},     // 4
    {7},     // 5
    {4},     // 6
    {6}      // 7
};

int dfs_clk = 0;
unordered_map<int, int> component;

void dfs(int u) {
  dfs_low[u] = dfs_num[u] = dfs_clk++, s.push_back(u);
  for (auto v : g[u]) {
    if (dfs_num[v] == UNVISITED) dfs(v);
    dfs_low[u] = min(dfs_low[u], dfs_low[v]);

    if (dfs_low[u] == dfs_num[u]) {
      // root of scc
      while (1) {
        int v = s.back();
        s.pop_back();
        component[v] = u;
        if (u == v) break;
      }
    }
  }
}

int main() {
  int n = 8;
  dfs_num.assign(n, UNVISITED), dfs_low.assign(n, UNVISITED);

  for (int i = 0; i < n; ++i)
    if (dfs_num[i] == UNVISITED) dfs(i);

  for (auto it : component)
    cout << it.first << " belongs to component " << it.second << endl;
  return 0;
}
