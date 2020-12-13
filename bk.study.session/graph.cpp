/**
 * @file graph
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday December 11 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define WHITE 0
#define GREY  1
#define BLACK 2
const int MXN = 1e4 + 7;

vi adj[MXN], color(MXN, WHITE);

// DFS O(V + E)
// DFS runs in O(V + E), but the time complexity of backtracking is exponential
void dfs(int u) {
  color[u] = GREY;

  for (auto v : adj[u]) {
    if (color[v] == WHITE) dfs(v);
  }

  color[u] = BLACK;
}

// DFS Spanning Tree O(V + E)
vi parent;

void dfs(int u) {
  color[u] = GREY;

  for (auto v : adj[u]) {
    if (color[v] == WHITE) dfs(v), parent[v] = u;  // in tree
  }

  color[u] = BLACK;
}

// Starting time, finishing time
int c = 0;  // clock
vi st(MXN, 0), ft(MXN, 0);
void dfs(int u) {
  st[u] = ++c;
  color[u] = GREY;

  for (auto v : adj[u]) {
    if (color[v] == WHITE) dfs(v), parent[v] = u;  // in tree
  }

  color[u] = BLACK;
  ft[u] = c;  // or ++c;
}

// Finding cut edges
// removing these edges will disconnect the graph
// At the beginning,
// dfs_low(u) = dfs_num(u) when vertex u is visited for the first time. Then, dfs_low(u)
// can only be made smaller if there is a cycle (a back edge exists). Note that we do not update
// dfs_low(u) with a back edge (u, v) if v is a direct parent of u.

// vi parent;
vi h(MXN, 0),   // h[u] = height of vertex u in the DFS tree
    d(MXN, 0);  // d[u] = min(h[w] where there is at least vertex v
// in subtree of u in the DFS tree
// where there is an edge between v and w).
// d(u) stores the lowest h reachable from the current
// DFS spanning subtree of u.

void dfs(int u) {
  d[u] = h[u] = ++c;
  color[u] = GREY;

  // update low links
  // back edge:
  // d[u] = min(d[u], h[v])
  // tree edge:
  // d[u] = min(d[u], d[v])
  // bi directional edge:
  // d[u] = min(d[u], d[v])

  // cut edge:
  // d[v] > h[u]:
  // min clock reachable from u has higher value than u's.
  // so removing it will disconnect the graph
  for (auto v : adj[u]) {
    if (color[v] == WHITE) {
      parent[v] = u, dfs(v), d[u] = min(d[u], d[v]);
      if (d[v] > h[u])
        ;                         // cut edge "u → v"
    } else if (v != parent[u]) {  // when we'r considering bi-directional edge u becomes the new v
      d[u] = min(d[u], h[v]);     // update only when its not bi-dir, only back edge
    }
  }
  color[u] = BLACK;
}

// Finding cut vertices
int root;  // start of dfs
vi children(MXN, 0);
void dfs(int u) {
  h[u] = d[u] = ++c, color[u] = GREY;

  for (auto v : adj[u]) {
    if (color[u] == WHITE) {
      ++children[u];
      parent[v] = u, dfs(v), d[u] = min(d[u], d[v]);
      if (d[v] >= h[u] && (u != root || children[u] > 1))
        ;  // cut vertex "u"
    } else if (v != parent[u]) {
      d[u] = min(d[u], h[v]);
    }
  }
  color[u] = BLACK;
}

// Finding Eulerian tours
vi etour;
void dfs(int u) {
  color[u] = GREY;
  while (!adj[u].empty()) {
    int v;
    v = adj[u].back(), adj[u].pop_back(), dfs(v);
  }
  color[u] = BLACK;
  etour.push_back(u);
}

// BFS
const int INF = 1e9 + 7;
vi d(MXN, INF);
void bfs(int s) {
  queue<int> q;
  q.push(s), d[s] = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : adj[u]) {
      if (d[v] == INF) d[v] = d[u] + 1, q.push(v), parent[v] = u;  // in spanning tree
    }
  }
}

// SCC - tarjan
vi s;  // stack for storing components for current tree
void dfs(int u) {
  d[u] = h[u] = ++c, s.push_back(u), color[u] = GREY;

  for (auto v : adj[u]) {
    if (color[v] == WHITE) dfs(v);
    if (color[v] == BLACK) d[u] = min(d[u], d[v]);  // condition for updating low links
  }

  if (d[u] == h[u]) {
    // start of scc
    while (1) {
      int v = s.back();
      s.pop_back();
      color[v] = WHITE;
      cout << v;  // same scc
      if (u == v) break;
    }
    cout << endl;
  }
}

// SCC - tarjan - alternate
vector<vi> scc;
void dfs(int u) {
  d[u] = h[u] = ++c;
  color[u] = GREY;

  for (auto v : adj[u]) {
    if (color[v] == WHITE) dfs(v);
    if (color[v] == BLACK) d[u] = min(d[u], d[v]);
  }

  if (d[u] == h[u]) {
    vi tmp;
    do {
      tmp.push_back(s.back()), s.pop_back();
    } while (s.back() != u);
    scc.push_back(tmp);
  }
}

// SSSP Dijkstra V + E log₂ V
#define ff first
#define ss second
typedef pair<int, int> ii;

vi d(MXN, INF);
void bfs(int s) {
  d[s] = 0;
  priority_queue<ii> q;
  q.push({0, -s});

  while (!q.empty()) {
    int w = -q.top().ff, u = -q.top().ss;
    q.pop();

    for (auto v : adj[u]) {
      if (d[u] + w < d[v]) {
        d[v] = d[u] + w;
        q.push({-d[v], -v});
      }
    }
  }
}

// APSP Floyd Warshall V³
void fw() {
  const int mxn = 400;
  vector<vi> d(mxn, vi(mxn, INF));  // 2D
  for (int i = 0; i < mxn; ++i) d[i][i] = 0;

  // for every edge u → v update d[u][v]

  for (int k = 0; k < mxn; ++k) {
    for (int i = 0; i < mxn; ++i) {
      for (int j = 0; j < mxn; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);  // can also be done using adj matrix AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]); without preprocessing edges
      }
    }
  }
}

// SSSP Bellman Ford VE
typedef vector<vector<ii>> vvii;
void bf(int s) {
  vvii adj;
  int V = MXN;
  vi d(V, INF);
  d[s] = 0;

  // O(V x E)
  for (int i = 0; i < V - 1; ++i) {
    // O(E)
    for (int u = 0; u < V; ++u) {
      for (auto v : adj[u]) {
        d[v.ff] = min(d[v.ff], d[u] + v.ss);
      }
    }
  }
}

// SPFA
/* 
Shortest Path Faster Algorithm (SPFA) is an algorithm that utilizes a queue to eliminate
redundant operations in Bellman Ford’s algorithm. 

SPFA requires the following data structures:
1. A graph stored in an Adjacency List: AdjList (see Section 2.4.1).
2. vi dist to record the distance from source to every vertex.
(vi is our shortcut for vector<int>).
3. A queue<int> to stores the vertex to be processed.
4. vi in queue to denote if a vertex is in the queue or not.
The first three data structures are the same as Dijkstra’s or Bellman Ford’s algorithms listed
in Section 4.4. The fourth data structure is unique to SPFA.
*/
vi d[MXN], inq[MXN];
void spfa(int s) {
  vvii adj;
  queue<int> q; q.push(s);

  while(!q.empty()) {
    int u = q.front(); q.pop(); inq[u] = 0;
    for(auto vw : adj[u]) {
      int v = vw.ff, w = vw.ss;
      if (d[u] + w < d[v]) {
        d[v] = d[u] + w;
        if(!inq[v]) inq[v] = 1, q.push(v);

      }
    }
  }
}

// TODO MST: Kruskals, Prims
