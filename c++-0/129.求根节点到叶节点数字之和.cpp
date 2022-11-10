/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
#include <stack>
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
  void dfs(TreeNode *root, int now, int &res) {
    now *= 10;
    now += root->val;
    if (!root->left && !root->right) {
      res += now;
      return;
    }
    if (root->left) {
      dfs(root->left, now, res);
    }
    if (root->right) {
      dfs(root->right, now, res);
    }
  }
  int sumNumbers(TreeNode *root) {
    int res = 0;
    dfs(root, 0, res);
    return res;
  }
};
// @lc code=end
