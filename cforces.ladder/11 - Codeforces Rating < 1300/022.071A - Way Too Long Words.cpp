/**
 * @file 022.071A - Way Too Long Words.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wed Jun 17 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n; cin >> n;

  while (n--) {
    string s; cin >> s;
    int k = s.size();

    if (k > 10) {
      cout << s[0] + to_string(k - 2) + s[k - 1] << endl;
    } else {
      cout << s << endl;
    }
  }

  return 0;
}
