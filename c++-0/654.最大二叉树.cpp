/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    deque<TreeNode *> que;
    for (int i = 0; i < nums.size(); ++i) {
      TreeNode *cur = new TreeNode(nums[i]);
      while (!que.empty() && nums[i] > que.back()->val) {
        cur->left = que.back();
        que.pop_back();
      }
      if (!que.empty()) {
        que.back()->right = cur;
      }
      que.push_back(cur);
    }
    return que.front();
  }
};
// @lc code=end
