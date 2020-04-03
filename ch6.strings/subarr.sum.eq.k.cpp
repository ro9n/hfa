#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int subarraySum(vector<int>& v, int k) {
        int f = 0, n = v.size(), p[n + 1];

        // create prefix table
        p[0] = 0;
        for (int i = 0; i < n; ++i) p[i + 1] = p[i] + v[i];

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (p[j] - p[i] == k) ++f;
            }
        }

        return f;
    }
};