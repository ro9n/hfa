#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& h) {
    if (h.empty()) return 0;
    int n = h.size(), l[n], r[n], trapped = 0;
    l[0] = 0, r[n - 1] = 0;

    for (int i = 1; i < n; ++i) {
      l[i] = max(l[i - 1], h[i - 1]);
    }

    for (int i = n - 2; i >= 0; --i) {
      r[i] = max(r[i + 1], h[i + 1]);
    }

    for (int i = 0; i < n; ++i) {
      trapped += max(0, min(l[i], r[i]) - h[i]);
    }

    return trapped;
  }
};

int main() {
  auto s = new Solution();
  vector<int> v{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  assert(s->trap(v) == 6);
  return 0;
}