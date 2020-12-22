/**
 * @file z
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday September 12 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

/**
 * Trivial implementation
 * O(n²)
 */
vi zf_trivial(string s) {
  int n = s.size();
  vi z(n);

  for (int i = 1; i < n; ++i)
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];

  // for(int i = 0; i < n; ++i) cerr << z[i] << ' '; cerr << endl;
  return z;
}

vi zf(string s) {
    int n = s.size(); vi z(n);

    for(int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) ++ z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }

    return z;
}

int main() {
  string s = "abcabc";
  zf_trivial(s);
  return 0;
}
