/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
  TreeNode *build(vector<int> &preorder, vector<int> &inorder,
                  map<int, int> &hash, int prel, int prer, int inl, int inr) {
    if (inl >= inr) {
      return nullptr;
    }
    int val = preorder[prel];
    TreeNode *root = new TreeNode(val);
    int pos = hash[val];
    root->left = build(preorder, inorder, hash, prel + 1,
                       prel + 1 + (pos - inl), inl, pos);
    root->right = build(preorder, inorder, hash, prel + 1 + (pos - inl), prer,
                        pos + 1, inr);
    return root;
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    map<int, int> hash;
    for (int i = 0; i < inorder.size(); ++i) {
      hash[inorder[i]] = i;
    }
    return build(preorder, inorder, hash, 0, preorder.size(), 0,
                 inorder.size());
  }
};
// @lc code=end
