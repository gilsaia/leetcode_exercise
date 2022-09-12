/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) {
      return true;
    }
    if (p && q && p->val == q->val) {
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    return false;
  }
  bool dfs(TreeNode *root, TreeNode *sub) {
    if (isSameTree(root, sub)) {
      return true;
    }
    bool res = false;
    if (root->left) {
      res |= dfs(root->left, sub);
    }
    if (root->right) {
      res |= dfs(root->right, sub);
    }
    return res;
  }
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    return dfs(root, subRoot);
  }
};
// @lc code=end
