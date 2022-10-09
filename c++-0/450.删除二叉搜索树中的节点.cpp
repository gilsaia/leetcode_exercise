/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr)
      return root; // 第一种情况：没找到删除的节点，遍历到空节点直接返回了
    if (root->val == key) {
      // 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
      if (root->left == nullptr && root->right == nullptr) {
        ///! 内存释放
        delete root;
        return nullptr;
      }
      // 第三种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位
      // ，返回右孩子为根节点
      else if (root->left == nullptr) {
        auto retNode = root->right;
        ///! 内存释放
        delete root;
        return retNode;
      }
      // 第四种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
      else if (root->right == nullptr) {
        auto retNode = root->left;
        ///! 内存释放
        delete root;
        return retNode;
      }
      // 第五种情况：左右孩子节点都不为空，则将删除节点的左子树放到删除节点的右子树的最左面节点的左孩子的位置
      // 并返回删除节点右孩子为新的根节点。
      else {
        TreeNode *cur = root->right; // 找右子树最左面的节点
        while (cur->left != nullptr) {
          cur = cur->left;
        }
        cur->left =
            root->left; // 把要删除的节点（root）左子树放在cur的左孩子的位置
        TreeNode *tmp = root; // 把root节点保存一下，下面来删除
        root = root->right;   // 返回旧root的右孩子作为新root
        delete tmp; // 释放节点内存（这里不写也可以，但C++最好手动释放一下吧）
        return root;
      }
    }
    if (root->val > key)
      root->left = deleteNode(root->left, key);
    if (root->val < key)
      root->right = deleteNode(root->right, key);
    return root;
  }
};
// class Solution {
// public:
//   TreeNode *prev;
//   TreeNode *findrightmost(TreeNode *cur) {
//     if (cur && cur->right) {
//       prev = cur;
//       return findrightmost(cur->right);
//     }
//     return cur;
//   }
//   TreeNode *findleftmost(TreeNode *cur) {
//     if (cur && cur->left) {
//       prev = cur;
//       return findrightmost(cur->left);
//     }
//     return cur;
//   }
//   TreeNode *deleteNode(TreeNode *root, int key) {
//     if (!root) {
//       return root;
//     }
//     TreeNode *cur = root;
//     TreeNode *allpre = nullptr;
//     while (cur) {
//       if (cur->val > key) {
//         allpre = cur;
//         cur = cur->left;
//         continue;
//       } else if (cur->val < key) {
//         allpre = cur;
//         cur = cur->right;
//         continue;
//       }
//       if (cur->left && cur->right) {
//         prev = cur;
//         TreeNode *tmp = findleftmost(cur->right);
//         tmp->left = cur->left;
//         cur->left = nullptr;
//         if (!allpre) {
//           root = root->right;
//         } else {
//           if (allpre->val > key) {
//             allpre->left = cur->right;
//           } else {
//             allpre->right = cur->right;
//           }
//         }
//         break;
//       }
//       if (cur->left) {
//         if (!allpre) {
//           root = root->left;
//           break;
//         }
//         if (allpre->val > key) {
//           allpre->left = cur->left;
//         } else {
//           allpre->right = cur->left;
//         }
//       } else if (cur->right) {
//         if (!allpre) {
//           root = root->right;
//           break;
//         }
//         if (allpre->val > key) {
//           allpre->left = cur->right;
//         } else {
//           allpre->right = cur->right;
//         }
//       } else {
//         if (!allpre) {
//           root = nullptr;
//           break;
//         }
//         if (allpre->val > key) {
//           allpre->left = nullptr;
//         } else {
//           allpre->right = nullptr;
//         }
//       }
//       break;
//     }
//     return root;
//   }
// };
// @lc code=end
