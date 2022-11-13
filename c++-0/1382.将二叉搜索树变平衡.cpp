/*
 * @lc app=leetcode.cn id=1382 lang=cpp
 *
 * [1382] 将二叉搜索树变平衡
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
  void build(TreeNode *root, vector<TreeNode *> &vec) {
    if (!root) {
      return;
    }
    build(root->left, vec);
    vec.push_back(root);
    build(root->right, vec);
  }
  TreeNode *recover(vector<TreeNode *> &vec, int left, int right) {
    if (left >= right) {
      return nullptr;
    }
    int mid = (left + right) / 2;
    TreeNode *tmp = vec[mid];
    tmp->left = recover(vec, left, mid);
    tmp->right = recover(vec, mid + 1, right);
    return tmp;
  }
  TreeNode *balanceBST(TreeNode *root) {
    vector<TreeNode *> vec;
    build(root, vec);
    return recover(vec, 0, vec.size());
  }
};
// @lc code=end
