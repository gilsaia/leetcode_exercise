/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
#include <map>
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
  TreeNode *pre;
  void dfs(TreeNode *root, vector<int> &res, int &count, int &maxcount) {
    if (root->left) {
      dfs(root->left, res, count, maxcount);
    }
    if (pre == nullptr) {
      maxcount = 1;
      count = 1;
      res.push_back(root->val);
    } else {
      if (pre->val == root->val) {
        ++count;
      } else {
        count = 1;
      }
      if (count == maxcount) {
        res.push_back(root->val);
      } else if (count > maxcount) {
        res.clear();
        maxcount = count;
        res.push_back(root->val);
      }
    }
    pre = root;
    if (root->right) {
      dfs(root->right, res, count, maxcount);
    }
  }
  vector<int> findMode(TreeNode *root) {
    vector<int> res;
    int count = 0, maxcount = 0;
    dfs(root, res, count, maxcount);
    return res;
  }
};
// @lc code=end
