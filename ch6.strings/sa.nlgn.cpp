#include <bits/stdc++.h>

using namespace std;

vector<int> sort_cyclic_shifts(const string &s) {
  int n = s.size();
  const int alphanet(256);
  vector<int> p(n), c(n), cnt(max(alphanet, n), 0);

  for (int i = 0; i < n; ++i) {
    ++cnt[s[i]];
  } 
}