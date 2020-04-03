#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& h) {
        int l = 0, n = h.size(), r = n - 1, best = 0;

        while (l < r) {
            best = max(best, min(h[l], h[r]) * (r - l));
            if (h[r] < h[l])
                --r;
            else
                ++l;
        }

        return best;
    }
};