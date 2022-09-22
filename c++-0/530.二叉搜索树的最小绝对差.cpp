/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
  void dfs(TreeNode *root, int &pre, int &ans) {
    if (root->left) {
      dfs(root->left, pre, ans);
    }
    if (pre == -1) {
      pre = root->val;
    } else {
      ans = min(ans, root->val - pre);
      pre = root->val;
    }
    if (root->right) {
      dfs(root->right, pre, ans);
    }
  }
  int getMinimumDifference(TreeNode *root) {
    int pre = -1, ans = INT_MAX;
    dfs(root, pre, ans);
    return ans;
  }
};
// @lc code=end
