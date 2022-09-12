/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */
class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  Node *connect(Node *root) {
    queue<Node *> que;
    if (!root) {
      return root;
    }
    que.push(root);
    Node *cur;
    while (!que.empty()) {
      int size = que.size();
      Node *tmp = nullptr;
      while (size--) {
        cur = que.front();
        que.pop();
        cur->next = tmp;
        tmp = cur;
        if (cur->right) {
          que.push(cur->right);
        }
        if (cur->left) {
          que.push(cur->left);
        }
      }
    }
    return root;
  }
};
// @lc code=end
