/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> sta;
    if (!root) {
      return res;
    }
    TreeNode *cur;
    sta.push(root);
    while (!sta.empty()) {
      cur = sta.top();
      sta.pop();
      if (cur) {
        if (cur->right) {
          sta.push(cur->right);
        }
        sta.push(cur);
        sta.push(nullptr);
        if (cur->left) {
          sta.push(cur->left);
        }
      } else {
        cur = sta.top();
        sta.pop();
        res.push_back(cur->val);
      }
    }
    return res;
  }
};
// @lc code=end
