/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  string removeDuplicates(string s) {
    stack<char> sta;
    for (char &c : s) {
      if (!sta.empty() && sta.top() == c) {
        sta.pop();
        continue;
      }
      sta.push(c);
    }
    string res;
    while (!sta.empty()) {
      res += sta.top();
      sta.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
