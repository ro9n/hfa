/**
 * @file topological.sort.tarjan
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday October 24 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

enum { UNVISITED,
       VISITED };

const int n = 8;

vi ts, g[n] = {{1, 2}, {2, 3}, {3, 5}, {4}, {}, {}, {}, {6}};

stack<int> s;
int dfs_num[n];

void dfs(int u) {
  dfs_num[u] = VISITED;
  for (auto v : g[u]) {
    if (dfs_num[v] == UNVISITED) dfs(v);
  }

  s.push(u);
}

int main() {
  ts.clear();
  memset(dfs_num, UNVISITED, sizeof dfs_num);

  for (int i = 0; i < n; ++i)
    if (dfs_num[i] == UNVISITED) dfs(i);

  while (!s.empty()) cout << s.top() << endl, s.pop();
  return 0;
}
