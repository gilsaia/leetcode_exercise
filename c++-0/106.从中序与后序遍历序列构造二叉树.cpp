/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
  TreeNode *build(vector<int> &inorder, vector<int> &postorder, int inl,
                  int inr, int postl, int postr, map<int, int> &hash) {
    if (inl >= inr) {
      return nullptr;
    }
    int val = postorder[postr - 1];
    TreeNode *root = new TreeNode(val);
    int pos = hash[val];
    root->left =
        build(inorder, postorder, inl, pos, postl, postr - (inr - pos), hash);
    root->right = build(inorder, postorder, pos + 1, inr, postl + (pos - inl),
                        postr - 1, hash);
    return root;
  }
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    map<int, int> hash;
    for (int i = 0; i < inorder.size(); ++i) {
      hash[inorder[i]] = i;
    }
    return build(inorder, postorder, 0, inorder.size(), 0, postorder.size(),
                 hash);
  }
};
// @lc code=end
