/**
 * @file mono.stack
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday October 02 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 8;
  vector<int> A{2, 9, 7, 8, 3, 4, 6, 1}, prev(n, -1), next(n, n);
  stack<int> s;

  for (int i = 0; i < n; ++i) {
    while (!s.empty() && A[s.top()] > A[i]) {
      int top = s.top();
      s.pop();
      next[top] = i;

      
    }
    prev[i] = s.empty() ? -1 : s.top();
    s.push(i);
  }

  for (int i = 0; i < n; ++i) cerr << setw(5) << i;
  cerr << endl;
  for (int i = 0; i < n; ++i) cerr << setw(5) << A[i];
  cerr << endl;
  for (int i = 0; i < n; ++i) cerr << setw(5) << prev[i];
  cerr << endl;
  for (int i = 0; i < n; ++i) cerr << setw(5) << next[i];
  cerr << endl;
  return 0;
}
