#include <bits/stdc++.h>

#define lf left
#define rg right
using namespace std;

class Solution {
  TreeNode* best;

  int dfs(TreeNode* r, TreeNode* p, TreeNode* q) {
    if (!r) {
      return 0;
    }

    int ans = (r == p || r == q) + dfs(r->lf, p, q) + dfs(r->rg, p, q);

    if (ans >= 2 && !best) {
      best = r;
    }

    return ans;
  }

 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    best = nullptr;
    dfs(root, p, q);
    return best;
  }
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *next;
};