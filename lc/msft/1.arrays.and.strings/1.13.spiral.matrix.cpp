#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& M) {
    vector<int> v;
    
    if(M.empty()) return v;

    int i = 0, j = 0, n = M.size(), m = M[0].size(), t = 0, l = 0, b = 0, r = 0;

    while (v.size() < n * m) {
      while (v.size() < n * m && j < m - r) v.eb(M[i][j++]);
      ++i, --j, ++t;
      while (v.size() < n * m && i < n - b) v.eb(M[i++][j]);
      --i, --j, ++r;
      while (v.size() < n * m && j >= 0 + l) v.eb(M[i][j--]);
      --i, ++j, ++b;
      while (v.size() < n * m && i >= 0 + t) v.eb(M[i--][j]);
      ++i, ++j, ++l;
    }

    return v;
  }
};

int main() {
  auto s = new Solution();

  vector<vector<int>> M{
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} /*, {13, 14, 15, 16}*/};

  s->spiralOrder(M);
  return 0;
}