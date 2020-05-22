#include <bits/stdc++.h>

using namespace std;

int n, m;
const int x[] = {-1, 1, 0, 0}, y[] = {0, 0, -1, 1};

void ff(vector<vector<char>>& M, int i, int j) {
  if (i < 0 || j < 0 || i >= n || j >= m) return;
  if (M[i][j] == '0') return;

  M[i][j] = '0';

  for (int k = 0; k < 4; ++k) {
    ff(M, i + x[k], j + y[k]);
  }
}

class Solution {
 public:
  int numIslands(vector<vector<char>>& M) {
    if (M.empty()) return 0;

    n = M.size();
    m = M[0].size();
    int ans = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (M[i][j] == '1') {
          ff(M, i, j);
          ++ans;
        }
      }
    }

    return ans;
  }
};