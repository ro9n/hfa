#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& M) {
    int n = M.size(), m = M[0].size();

    bool r[n], c[m];

    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!M[i][j]) r[i] = c[j] = 1;
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (r[i] || c[j]) M[i][j] = 0;
      }
    }
  }
};

int main() {
  auto s = new Solution();
  vector<vector<int>> M{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  s->setZeroes(M);

  return 0;
}