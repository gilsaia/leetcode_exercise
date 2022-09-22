/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
#include <deque>
#include <map>
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
  bool dfs(TreeNode *root, long long lower, long long upper) {
    if (root->val <= lower || root->val >= upper) {
      return false;
    }
    if (root->left) {
      bool res = dfs(root->left, lower, root->val);
      if (!res) {
        return false;
      }
    }
    if (root->right) {
      bool res = dfs(root->right, root->val, upper);
      if (!res) {
        return false;
      }
    }
    return true;
  }
  bool isValidBST(TreeNode *root) { return dfs(root, LONG_MIN, LONG_MAX); }
};
// @lc code=end
