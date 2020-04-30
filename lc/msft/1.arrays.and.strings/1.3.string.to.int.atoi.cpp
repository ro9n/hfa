#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define linr(v, l, r) (l <= v) && (v <= r)

inline bool number(int c) { return linr(c, 48, 57); }

inline bool wspace(int c) { return c == 32; }

inline bool letter(int c) { return linr(c, 65, 90) || linr(c, 97, 122); }

inline bool sign(int c) { return c == 43 || c == 45; }

class Solution {
 public:
  int myAtoi(const string& s) {
    int n = s.size(), l = 0;

    while (l < n && wspace(s[l])) ++l;

    ll v = 0;
    bool ngv = false;
    stack<int> st;

    if (!number(s[l]) && !sign(s[l]))
      return v;
    else if (sign(s[l])) {
      ngv = s[l++] == 45;
    }

    while (l < n && s[l] == 48) ++l;

    while (l < n && number(s[l])) {
      st.push(s[l++] - '0');
      if (st.size() > 10) return ngv ? INT_MIN : INT_MAX;
    }

    int i = 0;
    while (!st.empty()) {
      ll j = st.top() * pow(10, i);
      st.pop();
      if (ngv) j *= -1;

      if (v > 0 && v + j >= INT_MAX)
        return INT_MAX;
      else if (v + j <= INT_MIN)
        return INT_MIN;
      else {
        v += j;
        ++i;
      }
    }

    return v;
  }
};

int main() {
  auto s = new Solution();
  string t;
  while (getline(cin, t) && t != "q") {
    cout << s->myAtoi(t) << endl;
  }
  return 0;
}