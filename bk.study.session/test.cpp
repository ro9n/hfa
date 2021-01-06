/**
 * @file test
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday January 05 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  string s = "abc";

  int n = s.size();

  for(int i = 0; i < (1 << n); ++i) {
    for(int j = 0; j < n; ++j) {
      if (i & (1 << j)) cout << s[j];
    }
    cout << endl;
  }
  return 0;
}
