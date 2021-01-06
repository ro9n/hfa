/**
 * @file dsu.revisited
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wednesday January 06 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  return 0;
}

struct dsu {
  vector<int> parent, rank;

 public:
  void union_set(int u, int v);
  int find_set(int u);

  dsu(int n) {
    rank.assign(n, 0);
    parent.assign(n, 0);
    for (int i = 0; i < n; ++i) parent[i] = i;
  }
};

void dsu::union_set(int u, int v) {
  int a = find_set(u), b = find_set(v);

  if (a != b) {
    if (rank[a] < rank[b]) swap(a, b);  // make a greater
    parent[b] = a; // larger ranked node becomes parent
    if (rank[a] == rank[b]) rank[a]++;
  }
}

int dsu::find_set(int u) {
  if (u == parent[u]) return u;
  return parent[u] = find_set(parent[u]);
}