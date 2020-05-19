#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
  bool valid(TreeNode *r, ll lo, ll hi) {
    if (!r) return true;
    if (r->val <= lo || r->val >= hi) return false;
    return valid(r->left, lo, r->val) && valid(r->right, r->val, hi);
  }

 public:
  bool isValidBST(TreeNode *root) {
      return valid(root, INT_MIN -1ll, INT_MAX + 1ll);
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