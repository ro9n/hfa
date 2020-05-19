#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define N 1e4

typedef vector<int> vi;

class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (!root) return vector<vi>();

    vector<vi> v(N);
    queue<pair<TreeNode *, int>> q;
    int l = 0;

    q.push({root, 0});

    while (!q.empty()) {
      auto f = q.front(); q.pop();
      if (!f.first) continue;

      l = max(l, f.second);

      v[f.second].eb(f.first->val);
      q.push({f.first->left, f.second + 1});
      q.push({f.first->right, f.second + 1});
    }

    v.resize(l + 1);

    for (int i = 0; i < l + 1; ++i) {
      if (i & 1) reverse(v[i].begin(), v[i].end());
    }

    return v;
  }
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};