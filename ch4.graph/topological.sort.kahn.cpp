/**
 * @file topological.sort.kahn
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday October 24 2020
 *
 * @brief It looks like a modified BFS. Some problems, e.g.
 * UVa 11060 - Beverages, requires this Kahn's algorithm to produce the required topological
 * sort instead of the DFS-based algorithm shown earlier.
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int n = 8;

vi g[n] = {{1, 2}, {2, 3}, {3, 5}, {4}, {}, {}, {}, {6}};

int main() {
  int ind[n];  // indegree of vertex i

  memset(ind, 0, sizeof ind);

  for (int u = 0; u < n; ++u) {
    for (int v : g[u]) ++ind[v];
  }

  queue<int> q;  // priority queue in case ordering is needed
  vector<int> s;

  for (int u = 0; u < n; ++u)
    if (!ind[u]) q.push(u);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    s.push_back(u);
    for (auto v : g[u]) {
      --ind[v];
      if (!ind[v]) q.push(v);
    }
  }

  for(auto u: s) cout << u << endl;
  return 0;
}
