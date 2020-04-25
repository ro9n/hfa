#include <bits/stdc++.h>

using namespace std;

const int N = 15;
int z[N];

void zf(const string &s) {
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
      l = r = i;  // reset both l and r
      while (r < n && s[r - l] == s[r]) ++r;
      z[i] = r - l;  // +1 omitted, while increments r one more time
      --r;
    } else /* i <= r */ {
      //, i ≤ R, so the current [L, R] extends at least to i. Let k = i - L. We
      // know that Z[i] ≥ min(Z[k], R - i + 1) because S[i...] matches S[k...]
      // for at least R - i + 1 characters (they are in the [L, R] interval
      // which we know to be a prefix-substring). Now we have a few more cases
      // to consider.
      int k = i - l;
      if (z[k] < r - i + 1) {
        // If Z[k] < R - i + 1, then there is no longer prefix-substring
        // starting at S[i] (or else Z[k] would be larger), meaning Z[i] = Z[k]
        // and [L, R] stays the same. The latter is true because [L, R] only
        // changes if there is a prefix-substring starting at S[i] that extends
        // beyond R, which we know is not the case here.
        z[i] = z[k];
      } else {
        // If Z[k] ≥ R - i + 1, then it is possible for S[i...] to match S[0...]
        // for more than R - i + 1 characters (i.e. past position R). Thus we
        // need to update [L, R] by setting L = i and matching from S[R + 1]
        // forward to obtain the new R. Again, we get Z[i] during this.
        l = i;  // reset only l
        while (r < n && s[r - l] == s[r]) ++r;
        z[i] = r - l;
      }
    }
  }
}

int main() {
  string t = "baabaa", p = "aab";
  int n = p.size();
  zf(p + '$' + t);
  for (int i = 0; i < t.size() + p.size() + 1; ++i) {
    if (z[i] == n) cout << "found at index " << i - n - 1 << endl;
  }
  return 0;
}