#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back

typedef vector<int> vi;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int> &v) {
        vector<vi> vv;

        int n = v.size();

        if (n < 3) return vv;

        sort(v.begin(), v.end());

        for (int i = 0; i < n; ++i) {
            while (i > 0 && i < n && v[i - 1] == v[i]) ++i;

            int l = i + 1, r = n - 1;

            while (l < r) {
                int k = v[i] + v[l] + v[r];
                if (k < 0)
                    ++l;
                else if (k > 0)
                    --r;
                else {
                    vv.eb(vi{v[i], v[l++], v[r--]});

                    while (l < r && v[l - 1] == v[l]) l++;
                    while (l < r && v[r + 1] == v[r]) r--;
                }
            }
        }

        return vv;
    }
};