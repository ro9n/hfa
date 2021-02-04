/**
 * @file morris.tree
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday January 30 2021
 *
 * @brief 
 * Pseudo Code
 * 1. Initialize current as root 
 * 2. While current is not NULL
 *    If current has a left child
 *       if₁ Make current as right child of the rightmost 
 *          node in current's left subtree
 *       if₂ Go to this left child, i.e., current = current->left
 *    Else
 *      ea) Print current’s data
 *      eb) Go to the right, i.e., current = current->right
 * 
 */

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define ld left
#define rd right

typedef TreeNode t;

vector<int> inorderTraversal(TreeNode *root) {
  vector<int> ans;

  while (root) {
    if (root->ld) {                                      // If current has a left child
      t *pre = root->ld;                                 // if₁ Make current as right child of the rightmost node in current's left subtree
      while (pre->rd && pre->rd != root) pre = pre->rd;  // Make current as the right child of its inorder predecessor
      
      if (!pre->rd) pre->rd = root, root = root->ld;     // if₂ Go to this left child, i.e., current = current->left
      else {                                             // Revert the changes made in the 'if' part to restore the original tree i.e., fix the right child of predecessor
        pre->rd = 0, ans.push_back(root->val), root = root->rd;
      }
    } else {
      ans.push_back(root->val), root = root->rd;
    }
  }

  return ans;
}
