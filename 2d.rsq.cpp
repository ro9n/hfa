/**
 * @file 2d.rsq
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wednesday March 03 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m,
      mat[n][m],
      sum,
      start_y, start_x, end_y, end_x;

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
    }
  }

  sum = mat[end_y][end_x];
  if (start_y > 0) sum -= mat[start_y - 1][end_x];
  if (start_x > 0) sum -= mat[end_y][start_x - 1];
  if (start_y > 0 && start_x > 0) sum += mat[start_y - 1][start_x - 1];
}
