/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
#include <string>
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
  void dfs(TreeNode *root, vector<string> &res, string now) {
    now += "->" + to_string(root->val);
    if (!root->left && !root->right) {
      res.push_back(now);
    } else {
      if (root->left) {
        dfs(root->left, res, now);
      }
      if (root->right) {
        dfs(root->right, res, now);
      }
    }
  }
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> ans;
    if (!root) {
      return ans;
    }
    string now = to_string(root->val);
    if (!root->left && !root->right) {
      ans.push_back(now);
      return ans;
    }
    if (root->left) {
      dfs(root->left, ans, now);
    }
    if (root->right) {
      dfs(root->right, ans, now);
    }
    return ans;
  }
};
// @lc code=end
