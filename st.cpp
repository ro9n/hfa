//
// Created by Touhid Alam on 3/18/20.
//

#include "st.h"

#define l(p) (p << 1)
#define r(p) (p << 1) + 1


st::st(std::vector<int> const &v) {
    c = v;
    int n = (int) c.size();

    // create large enough vector of 0s
    t.assign(4 * n, 0);
    build(1, 0, n - 1);
}

void st::build(int p, int l, int r) {
    if (l == r) t[p] = l; // or r, store the index of min
    else {
        build(l(p), l, (l + r) / 2);
        build(r(p), (l + r) / 2 + 1, r);
        // backtrack
        // index of left, right segment min
        int lsm = t[l(p)], rsm = t[r(p)];
        // compare the values of both index
        t[p] = c[lsm] <= c[rsm] ? lsm : rsm;
    }
}

int st::rmq(int l, int r) {
    int n = (int) c.size();
    return rmq(l, r, 1, 0, n - 1);
}

int st::rmq(int l, int r, int p, int L, int R) {
    // base case: query outside range
    if (l > R || r < L) return -1;
    // base case: inside query range
    if (l <= L && r >= R) return t[p];

    // compute min
    int rmq_l = rmq(l, r, l(p), L, (L + R) / 2), rmq_r = rmq(l, r, r(p), (L + R) / 2 + 1, R);
    // trying to access segment outside range
    if (rmq_l == -1) return rmq_r;
    else if (rmq_r == -1) return rmq_l;
    else return c[rmq_l] <= c[rmq_r] ? rmq_l : rmq_r;
}

