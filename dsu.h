//
// Created by Touhid Alam on 3/18/20.
//

#ifndef HFA_DSU_H
#define HFA_DSU_H

#include <vector>

/**
 * Disjoint Set Union
 * a.k.a Union Find Data Structure
 */
class dsu {
public:
    explicit dsu(int n);
    bool is_same_set(int u, int v);
    int find_set(int u);
    void union_sets(int u, int v);

private:
    std::vector <int> p, r; // parent, rank
};

#endif //HFA_DSU_H
