/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <stack>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  bool isValid(string s) {
    stack<char> sta;
    for (char &c : s) {
      if (c == '(' || c == '[' || c == '{') {
        sta.push(c);
      } else {
        if (sta.empty()) {
          return false;
        }
        char now = sta.top();
        if ((c == ')' && now != '(') || (c == '}' && now != '{') ||
            (c == ']' && now != '[')) {
          return false;
        }
        sta.pop();
      }
    }
    return sta.empty();
  }
};
// @lc code=end
