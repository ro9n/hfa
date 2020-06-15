#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define INF 100000000000LL
class Solution {
    bool valid(TreeNode* r, long long lo, long long hi) {
        if (!r)
            return true;
        else if (r->val <= lo || r->val >= hi)
            return false;
        else if (r->left && r->left->val >= r->val)
            return false;
        else if (r->right && r->right->val <= r->val)
            return false;
        else
            return valid(r->left, lo, r->val) && valid(r->right, r->val, hi);
    }

   public:
    bool isValidBST(TreeNode* root) {
        return valid(root, -INF, INF);
    }
};