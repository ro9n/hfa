#include <bits/stdc++.h>

using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define fill(c, v) memset(c, v, sizeof c)
#define eb emplace_back

const int V = 1e4 + 7;

typedef pair<int, int> ii;
typedef vector<int> vi;

// for weighted grapg vector<ii> g[V]
vi g[V], s;

int t = 0, d[V], l[V], c[V];  // dfs clock, dfs low links, dfs colors, stack to print scc from root

void dfs(int u, int p = -1) {
  l[u] = d[u] = ++t;
  c[u] = GRAY;
  s.eb(u);

  for (int v : g[u]) {
    if (v == p) continue;
    if (c[v] == WHITE) {
      dfs(v, u);
    } 
    
    if (c[v] == BLACK) {
      l[u] = min(l[u], l[v]);
    }
  }
  c[u] = BLACK;

  if(d[u] == l[u]) {
    // root of scc
    while(s.back() != u) {
      cout << s.back() << ' '; s.pop_back(); 
    }
    cout << endl;
  }
}

int main() {
  fill(c, WHITE);
  return 0;
}
