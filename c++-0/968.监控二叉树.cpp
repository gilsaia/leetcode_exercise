/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
  void dfs(TreeNode *root, int &res) {
    if (!root) {
      return;
    }
    dfs(root->left, res);
    dfs(root->right, res);
    if (!root->left && !root->right) {
      root->val = -1;
      return;
    }
    if ((root->left && root->left->val == -1) ||
        (root->right && root->right->val == -1)) {
      root->val = 1;
      ++res;
      return;
    }
    if ((root->left && root->left->val == 1) ||
        (root->right && root->right->val == 1)) {
      root->val = 2;
      return;
    }
    root->val = -1;
    return;
  }
  int minCameraCover(TreeNode *root) {
    int res = 0;
    dfs(root, res);
    if (root->val == -1) {
      ++res;
    }
    return res;
  }
};
// @lc code=end
