/**
 * @file tarjan.scc.it2
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday September 29 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define UNVISITED 0

// scc in directed graph
vector<int> dfs_num, dfs_low, s, visited;
vector<vector<int>> g;
int dfs_clock, scc;

void dfs(int u) {
  dfs_num[u] = dfs_low[u] = ++dfs_clock;
  s.emplace_back(u);

  for(auto v: g[u]){
    if (dfs_num[v] == UNVISITED) dfs(v);
    if(visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }

  if (dfs_num[u] == dfs_low[u]) {
    ++scc;
    while(s.back() != u) {
      cout << s.back(); s.pop_back();
    }
    cout << endl;
  }
}

int main() {
  return 0;
}
