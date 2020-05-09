#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& M) {
    int n = M.size(), m = M[0].size();

    bool fcol0 = false;

    for (int j = 0; j < m; ++j) {
      if (!M[0][j]) {
        fcol0 = true;
        break;
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!M[i][j]) {
          M[0][j] = 0;
        }
      }
    }

    for (int i = 1; i < n; ++i) {
      bool row0 = false;
      for (int j = 0; j < m; ++j) {
        if (!M[i][j]) {
          row0 = true;
        }
      }
      for (int j = 0; j < m; ++j) {
        if (row0 || !M[0][j]) M[i][j] = 0;
      }
    }
    
    if (fcol0) {
      for (int j = 0; j < m; ++j) {
        M[0][j] = 0;
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