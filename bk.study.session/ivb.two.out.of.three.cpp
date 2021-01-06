/**
 * @file ivb.two.out.of.three
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday January 05 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B, vector<int> &C) {
  unordered_map<int, int> freq;
  unordered_set<int> curr;

  for (auto k : A) {
    if (!curr.count(k)) {
      curr.insert(k), ++freq[k];
    }
  }
  curr.clear();
  for (auto k : B) {
    if (!curr.count(k)) {
      curr.insert(k), ++freq[k];
    }
  }
  curr.clear();
  for (auto k : C) {
    if (!curr.count(k)) {
      curr.insert(k), ++freq[k];
    }
  }

  vector<int> ans;
  for (auto it : freq) {
    if (it.second >= 2)
      ans.push_back(it.first);
  }

  sort(ans.begin(), ans.end());
  return ans;
}
