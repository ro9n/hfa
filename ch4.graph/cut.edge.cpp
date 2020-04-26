/**
 * cut edges / bridges
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

// for weighted grapg vector<ii> g[V]
vi g[V];

int t = 0, d[V], l[V], c[V];  // dfs clock, dfs low links, dfs colors

void dfs(int u, int p = -1) {
  l[u] = d[u] = ++t;
  c[u] = GRAY;
  for (int v : g[u]) {
    if (v == p) continue;
    if (c[v] == WHITE) {
      dfs(v, u);

      if (d[u] < l[v]) {
        cout << u << "->" << v << "is a cut edge";
      }
    } else {
      l[u] = min(l[u], d[v]);
    }
  }
  c[u] = BLACK;
}

int main() {
  fill(c, WHITE);
  return 0;
}
