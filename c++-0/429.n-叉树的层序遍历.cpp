/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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
class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> res;
    queue<Node *> que;
    if (!root) {
      return res;
    }
    que.push(root);
    Node *cur;
    while (!que.empty()) {
      int size = que.size();
      vector<int> tmp;
      while (size--) {
        cur = que.front();
        que.pop();
        tmp.push_back(cur->val);
        for (auto &child : cur->children) {
          que.push(child);
        }
      }
      res.push_back(tmp);
    }
    return res;
  }
};
// @lc code=end
