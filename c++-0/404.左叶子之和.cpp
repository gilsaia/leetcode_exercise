/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
  bool isLeaf(TreeNode *root) { return !(root->left || root->right); }
  int sumOfLeftLeaves(TreeNode *root) {
    int res = 0;
    if (!root) {
      return res;
    }
    if (root->left && isLeaf(root->left)) {
      res += root->left->val;
    }
    if (root->left) {
      res += sumOfLeftLeaves(root->left);
    }
    if (root->right) {
      res += sumOfLeftLeaves(root->right);
    }
    return res;
  }
};
// @lc code=end
