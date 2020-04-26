/**
 * cut vertices / articulation points
 * */

#include <bits/stdc++.h>

using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define fill(c, v) memset(c, v, sizeof c)

const int V = 1e4 + 7;

typedef pair<int, int> ii;
typedef vector<int> vi;

// for weighted graph vector<ii> g[V]
vi g[V];

int t = 0, d[V], l[V], c[V],
    root_children = 0;  // dfs clock, dfs low links, dfs colors, root children

void dfs(int u, int p = -1) {
  l[u] = d[u] = ++t;
  c[u] = GRAY;
  for (int v : g[u]) {
    if (v == p) continue;
    if (c[v] == WHITE) {
      if (p == -1) ++root_children;
      dfs(v, u);

      if (d[u] <= l[v]) {
        cout << u << "is a cut vertex";
      }
      l[u] = min(l[u], l[v]);
    } else {
      l[u] = min(l[u], d[v]);
    }
  }
  c[u] = BLACK;
  if (p == -1 && root_children > 1) cout << u << "is a cut vertex";
}

int main() {
  fill(c, WHITE);
  return 0;
}
