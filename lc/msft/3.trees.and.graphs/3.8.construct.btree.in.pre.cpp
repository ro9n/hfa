#include <bits/stdc++.h>

using namespace std;

#define lf left
#define rg right

map<int, int> m;  // inorder indecies;
int i, n;         // preorder index, size

class Solution {
  TreeNode* build(int L, int R, vector<int>& pre) {
    if (L > R) return 0;

    TreeNode* r = new TreeNode(pre[i]);
    int k = m[pre[i]];

    ++i;

    r->lf = build(L, k - 1, pre);
    r->rg = build(k + 1, R, pre);

    return r;
  }

 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()) return 0;

    for (int i = 0; i < inorder.size(); ++i) {
      m[inorder[i]] = i;
    }

    n = inorder.size();
    i = 0;

    return build(0, n - 1, preorder);
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