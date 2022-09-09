/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
  vector<int> preorderTraversal(TreeNode *root) {
    stack<TreeNode *> sta;
    vector<int> res;
    TreeNode *cur;
    sta.push(root);
    while (!sta.empty()) {
      cur = sta.top();
      sta.pop();
      if (!cur) {
        continue;
      }
      res.push_back(cur->val);
      sta.push(cur->right);
      sta.push(cur->left);
    }
    return res;
  }
};
// @lc code=end
class Solution_2 {
public:
  void dfs(TreeNode *cur, vector<int> &res) {
    if (!cur) {
      return;
    }
    res.push_back(cur->val);
    dfs(cur->left, res);
    dfs(cur->right, res);
  }
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    dfs(root, res);
    return res;
  }
};