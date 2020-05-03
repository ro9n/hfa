#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
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

    l = r = 0;
    while (r < n) {
      while (r < n && s[r] == ' ') ++r;
      while (r < n && s[r] != ' ') swap(s[l++], s[r++]);
      s[l++] = ' ';
    }

    --l;
    if (l > 0 && s[l - 1] == ' ') --l;
    return s.substr(0, l);
  }
};

int main() {
  auto s = new Solution();
  string i = "     hello! world          ";
  cout << s->reverseWords(i) << '<' << endl;
  return 0;
}