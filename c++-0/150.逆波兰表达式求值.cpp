/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include <stack>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> sta;
    for (string &s : tokens) {
      if (s.size() > 1 || (s[0] >= '0' && s[0] <= '9')) {
        int tmp = stoi(s);
        sta.push(tmp);
      } else {
        int a = sta.top();
        sta.pop();
        int b = sta.top();
        sta.pop();
        switch (s[0]) {
        case '+':
          sta.push(a + b);
          break;
        case '-':
          sta.push(b - a);
          break;
        case '*':
          sta.push(a * b);
          break;
        case '/':
          sta.push(b / a);
          break;
        default:
          break;
        }
      }
    }
    return sta.top();
  }
};
// @lc code=end
