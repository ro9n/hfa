#include <bits/stdc++.h>

using namespace std;

string h(const string& s) {
  unordered_map<int, int> f;
  string r;
  for (auto c : s) ++f[c - 'a'];
  for (int i = 0; i < 26; ++i) {
    if (i < 10) r += to_string('0');
    r += to_string(i);
    r += to_string(f[i]);
  }
  return r;
}

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> m;

    for (auto s : strs) {
      m[h(s)].emplace_back(s);
    }

    vector<vector<string>> r;
    for (auto s : m) r.emplace_back(s.second);

    return r;
  }
};

int main() {
  auto s = new Solution();
  vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
  auto r = s->groupAnagrams(v);
  for (auto x : r) {
    for (auto y : x) {
      cout << y << ",";
    }
    cout << endl;
  }

  return 0;
}