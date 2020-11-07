/**
 * @file ap.bridge.undirected
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday October 24 2020
 *
 * @brief Articulation Point/ Cut Vertex and Bridge/Cut Edge
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

enum { UNVISITED };

vi g[n] = {{1}, {0, 2, 3, 4, 5}, {1}, {1, 5}, {1, 4}};

const int n = 6;
int dfs_num[n], dfs_low[n], dfs_parent[n], dfs_clk = 0, root_children = 0, dfs_root, cut_vtx[n], cut_edge[n];

enum { UNVISITED };

void dfs(int u) {
  dfs_low[u] = dfs_num[u] = dfs_clk++;

  for (int v : g[u]) {
    if (dfs_num[u] == UNVISITED) {
      // Tree Edge
      dfs_parent[v] = u;
      if (u == dfs_root) ++root_children;

      dfs(v);

      if (dfs_low[v] >= dfs_num[u]) cut_vtx[u] = 1;
      if (dfs_low[v] > dfs_num[u]) cut_edge[u] = 1;

      dfs_low[u] = min(dfs_low[u], dfs_low[v]);  // for tree edge, use dfs_lowᵥ to minimize
    } else if (v != dfs_parent[u]) {             // dfs_num[v] == EXPLORED, E → E
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);  // for back edge, use dfs_numᵥ to minimize
    }
  }
}

int main() {
  // TODO clear arrays
  for (int i = 0; i < n; ++i) {
    dfs_root = i, root_children = 0, dfs(i);
    cut_vtx[dfs_root] = root_children > 1;
  }
  return 0;
}
