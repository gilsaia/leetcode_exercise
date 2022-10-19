/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
#include <algorithm>
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
  void dfs(TreeNode *root, int &withoutval, int &withval) {
    if (!root) {
      return;
    }
    int leftwithoutval = 0, leftwithval = 0, rightwithoutval = 0,
        rightwithval = 0;
    dfs(root->left, leftwithoutval, leftwithval);
    dfs(root->right, rightwithoutval, rightwithval);
    withoutval = leftwithval + rightwithval;
    withval = max(leftwithoutval + rightwithoutval + root->val, withoutval);
    return;
  }
  int rob(TreeNode *root) {
    int withoutval = 0, withval = 0;
    dfs(root, withoutval, withval);
    return withval;
  }
};
// @lc code=end
