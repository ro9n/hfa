//
// Created by Touhid Alam on 3/18/20.
//

#include "dsu.h"

dsu::dsu(int n) {
    p.assign(n, 0);
    for (int i = 0; i < n; ++i) p[i] = i;
    r.assign(n, 0);
}

bool dsu::is_same_set(int u, int v) {
    return find_set(u) == find_set(v);
}

int dsu::find_set(int u) {
    return (p[u] == u) ? u : (p[u] = find_set(p[u]));
}

void dsu::union_sets(int u, int v) {
    u = find_set(u), v = find_set(v);
    if (r[u] > r[v]) p[v] = u;
    else {
        p[u] = v;
        if (r[u] == r[v]) ++r[v];
    }
}
