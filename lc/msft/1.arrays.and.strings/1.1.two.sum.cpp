#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& v, int k) {
    map<int, int> m;
    for (int i = 0; i < v.size(); ++i) {
      if (!m.count(k - v[i])) {
        m[v[i]] = i;
      } else
        return vector<int>{m[k - v[i]], i};
    }

    return vector<int>{-1, -1};
  }
};