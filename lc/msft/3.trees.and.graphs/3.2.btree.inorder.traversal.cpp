#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    TreeNode *r = root;
    stack<TreeNode *> s;
    vector<int> v;

    while (r || !s.empty()) {
      while (r) {
        s.push(r);
        r = r->left;
      }
      r = s.top(); s.pop();
      v.eb(r->val);
      r = r->right;
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