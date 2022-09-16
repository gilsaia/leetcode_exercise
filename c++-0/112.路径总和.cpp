/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
  bool dfs(TreeNode *root, int cur, int &target) {
    cur += root->val;
    if (!(root->left || root->right)) {
      return cur == target;
    }
    bool res = false;
    if (root->left) {
      res |= dfs(root->left, cur, target);
    }
    if (res) {
      return true;
    }
    if (root->right) {
      res |= dfs(root->right, cur, target);
    }
    return res;
  }
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root) {
      return false;
    }
    return dfs(root, 0, targetSum);
  }
};
// @lc code=end
