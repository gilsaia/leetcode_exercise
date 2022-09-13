/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
  int countNodes(TreeNode *root) {
    if (!root) {
      return 0;
    }
    int res = 1;
    TreeNode *cur = root;
    while (cur) {
      if (cur->left) {
        res++;
        cur = cur->left;
      } else {
        break;
      }
    }
    int left = 1 << (res - 1), right = left * 2, mid;
    while (left < right) {
      mid = (right - left + 1) / 2 + left;
      int tmp = res - 1;
      cur = root;
      while (tmp) {
        cur = ((mid >> (tmp - 1)) & 1) ? cur->right : cur->left;
        --tmp;
      }
      if (cur) {
        left = mid;
      } else {
        right = mid - 1;
      }
    }
    return left;
  }
};
// @lc code=end
