/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    if (s.size() == 1) {
      return false;
    }
    vector<int> next(s.size(), -1);
    int i = 1, j = -1;
    while (i < s.size()) {
      while (j >= 0 && s[i] != s[j + 1]) {
        j = next[j];
      }
      if (s[i] == s[j + 1]) {
        ++j;
      }
      next[i] = j;
      ++i;
    }
    int len = s.size();
    if (next[len - 1] != -1 && len % (len - next[len - 1] - 1) == 0) {
      return true;
    }
    return false;
  }
};
// @lc code=end
