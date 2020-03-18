//
// Created by Touhid Alam on 3/18/20.
//

#ifndef HFA_ST_H
#define HFA_ST_H

#include <vector>

/**
 * Segment Tree
 * for solving dynamic RMQ
 */
class st {
public:
    explicit st(std::vector<int> const& A);
    int rmq(int l, int r);

private:
    std::vector<int> t, c; // segment tree, container of original data vector
    void build(int p, int l, int r);
    int rmq(int l, int r, int p, int L, int R);
};


#endif //HFA_ST_H
