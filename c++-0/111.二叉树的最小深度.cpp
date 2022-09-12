/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
  int minDepth(TreeNode *root) {
    queue<TreeNode *> que;
    if (!root) {
      return 0;
    }
    que.push(root);
    TreeNode *cur;
    int res = 0;
    while (!que.empty()) {
      int size = que.size();
      ++res;
      while (size--) {
        cur = que.front();
        que.pop();
        if (cur->left) {
          que.push(cur->left);
        }
        if (cur->right) {
          que.push(cur->right);
        }
        if (!cur->left && !cur->right) {
          return res;
        }
      }
    }
    return res;
  }
};
// @lc code=end
