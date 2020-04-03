#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& v, int k) {
        unordered_map<int, int> m;

        int n = v.size();

        for (int i = 0; i < n; ++i) {
            int j = k - v[i];
            if (m.find(j) != m.end())
                return {i, m.find(j)->second};
            else
                m.insert({v[i], i});
        }

        return {-1};
    }
};