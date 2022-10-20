/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  bool isSubsequence(string s, string t) {
    if (s.size() == 0) {
      return true;
    }
    int ind = 0;
    for (int i = 0; i < t.size(); ++i) {
      if (t[i] == s[ind]) {
        ++ind;
        if (ind == s.size()) {
          return true;
        }
      }
    }
    return false;
  }
};
// @lc code=end
