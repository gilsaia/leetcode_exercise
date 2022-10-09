/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (!root) {
      root = new TreeNode(val);
      return root;
    }
    TreeNode *cur = root;
    while (true) {
      if (cur->val > val && cur->left) {
        cur = cur->left;
        continue;
      }
      if (cur->val < val && cur->right) {
        cur = cur->right;
        continue;
      }
      TreeNode *tmp = new TreeNode(val);
      if (cur->val > val) {
        cur->left = tmp;
      } else {
        cur->right = tmp;
      }
      break;
    }
    return root;
  }
};
// @lc code=end
