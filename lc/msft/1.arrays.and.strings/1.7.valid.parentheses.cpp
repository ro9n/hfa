#include <bits/stdc++.h>

using namespace std;

inline bool openbr(const char& c) { return c == '(' || c == '{' || c == '['; }

inline char pairbr(const char& c) {
  switch (c) {
    case ')':
      return '(';
    case '}':
      return '{';
    case ']':
      return '[';
    default:
      return '\0';
  }
}

class Solution {
 public:
  bool isValid(string s) {
    stack<char> st;
    for (auto c : s) {
      if (openbr(c))
        st.push(c);
      else {
        if (st.empty() || pairbr(c) != st.top())
          return false;
        else
          st.pop();
      }
    }
    return st.empty();
  }
};

int main() {
  auto s = new Solution();
  if (s->isValid("()")) {
    cout << "valid";
  }

  return 0;
}