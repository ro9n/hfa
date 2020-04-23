#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int z[N];

int zmatch(const string &s) {
  int l = 0, r = 0, n = s.size();
  // [l, r] window that matches with prefix of s
  // [l, r] which is the interval with maximum r such that 1 ≤ l ≤ i ≤ r and
  // S[l...r] is a prefix-substring

  for (int i = 1; i < n; ++i) {
    if (i > r) {
      // If i > R, then there does not exist a prefix-substring of S that starts
      // before i and ends at or after i. If such a substring existed, [L, R]
      // would have been the interval for that substring rather than its current
      // value. Thus we "reset" and compute a new [L, R] by comparing S[0...] to
      // S[i...] and get Z[i] at the same time ( Z[i] = R - L + 1) not matching
      l = r = i;  // reset
      while (r < n && s[r - l] == s[r]) ++r;
      z[i] = r - l;
      --r;
    }
  }
}

int main() { return 0; }