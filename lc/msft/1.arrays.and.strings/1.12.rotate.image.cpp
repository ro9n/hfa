#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>>& M) {
    int n = M.size();
    // transpose (i, j) -> (j, i)
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        swap(M[i][j], M[j][i]);
      }
    }
    // flip horizontally (i, j) -> (i, m - 1 - j)
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n >> 1; ++j) {
        swap(M[i][j], M[i][n - j - 1]);
      }
    }
  }
};

int main() {
  auto s = new Solution();
  vector<vector<int>> M{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  s->rotate(M);

  return 0;
}