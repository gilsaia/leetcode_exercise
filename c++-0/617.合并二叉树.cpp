/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (!root1 && !root2) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(0);
    if (root1) {
      root->val += root1->val;
    }
    if (root2) {
      root->val += root2->val;
    }
    root->left = mergeTrees(root1 ? root1->left : nullptr,
                            root2 ? root2->left : nullptr);
    root->right = mergeTrees(root1 ? root1->right : nullptr,
                             root2 ? root2->right : nullptr);
    return root;
  }
};
// @lc code=end
