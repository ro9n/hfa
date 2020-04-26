#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 7;

int Z[MAXN];

void z(const string &s) {
  int n = s.size();
  memset(Z, 0, n);

  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    if (i > r) {
      l = r = i;
      while (r < n && s[r - l] == s[r]) ++r;
      Z[i] = r-- - l;
    } else {
      int k = i - l;
      if (Z[k] < r - i + 1)
        Z[i] = Z[k];
      else {
        l = i;
        while (r < n && s[r - l] == s[r]) ++r;
        Z[i] = r-- - l;
      }
    }
  }
}

int main() {
  string t, p;  // text, pattern
  cin >> t >> p;
  string c = p + '$' + t;
  z(c);

  for (int i = 0; i < c.size(); ++i) {
    if (Z[i] == p.size()) cout << "Found at index " << i - p.size() - 1 << endl;
  }
}