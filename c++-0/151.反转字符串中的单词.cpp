/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */
#include <algorithm>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  string reverseWords(string s) {
    int slow = 0, fast = 0;
    bool isWord = true;
    while (fast < s.size()) {
      if (isWord && s[fast] == ' ') {
        ++fast;
        continue;
      }
      if (s[fast] == ' ') {
        isWord = true;
      } else {
        isWord = false;
      }
      s[slow] = s[fast];
      ++slow;
      ++fast;
    }
    if (s[slow - 1] == ' ') {
      --slow;
    }
    s.erase(s.begin() + slow, s.end());
    reverse(s.begin(), s.end());
    slow = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') {
        reverse(s.begin() + slow, s.begin() + i);
        slow = i + 1;
      }
    }
    reverse(s.begin() + slow, s.end());
    return s;
  }
};
// @lc code=end
