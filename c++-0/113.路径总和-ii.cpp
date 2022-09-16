/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
  void dfs(TreeNode *root, int cur, int &target, vector<int> &path,
           vector<vector<int>> &res) {
    cur += root->val;
    path.push_back(root->val);
    if (!(root->left || root->right)) {
      if (cur == target) {
        res.push_back(path);
      }
    }
    if (root->left) {
      dfs(root->left, cur, target, path, res);
      path.pop_back();
    }
    if (root->right) {
      dfs(root->right, cur, target, path, res);
      path.pop_back();
    }
  }
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<vector<int>> res;
    vector<int> path;
    if (!root) {
      return res;
    }
    dfs(root, 0, targetSum, path, res);
    return res;
  }
};
// @lc code=end
