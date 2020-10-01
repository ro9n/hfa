/**
 * @file articulation.point
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday September 29 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define UNVISITED 0
#define VISITED 1

vector<int> dfs_num, dfs_low, ap;
vector<pair<int, int>> bridge;
int dfs_clock, dfs_root, root_children;
vector<vector<int>> g;

void dfs(int u, int parent) {
  dfs_num[u] = dfs_low[u] = ++dfs_clock;

  for(auto v: g[u]) {
    if(dfs_num[u] == UNVISITED) {
      if (u == dfs_root) ++root_children;
      dfs(v, u);

      if(dfs_low[v] >= dfs_num[u]) ap.emplace_back(u);
      if(dfs_low[v] > dfs_num[u]) bridge.emplace_back(make_pair(u, v));

      dfs_low[u] = min(dfs_low[u], dfs_low[v]); // tree
    } else if(v != parent) {
      dfs_low[u] = min(dfs_low[u], dfs_num[v]); // back/cross

    }
  }
}

int main() {
  int V;
  for(int i = 0; i < V; ++i) {
    dfs_root = i;
    dfs(i, -1);

    if (root_children > 1) ap.emplace_back(i);
  }
  return 0;
}
