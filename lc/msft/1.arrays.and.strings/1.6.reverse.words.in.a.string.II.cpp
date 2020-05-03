#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void reverseWords(vector<char>& s) {
    int n = s.size(), l = 0, r = n - 1;

    while (l < r) {
      swap(s[l++], s[r--]);
    }

    l = r = 0;
    int b, e;

    while (r < n) {
      while (r < n && s[r] == ' ') ++r;
      b = r;
      while (r < n && s[r] != ' ') ++r;
      e = r - 1;

      while (b < e) swap(s[b++], s[e--]);
    }
  }
};