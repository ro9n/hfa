#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int trap(vector<int>& h) {
        if (h.empty()) return 0;
        int n = h.size(), l[n], r[n], total = 0;

        memset(l, 0, sizeof l), memset(r, 0, sizeof r);

        l[0] = h[0], r[n - 1] = h[n - 1];

        for (int i = 1; i < n; ++i)
            l[i] = max(l[i - 1], h[i]);
        for (int j = n - 2; j >= 0; --j)
            r[j] = max(r[j + 1], h[j]);

        for (int i = 0; i < n; ++i) total += min(l[i], r[i]) - h[i];

        return total;
    }
};