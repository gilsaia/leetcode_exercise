/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  bool backspaceCompare(string s, string t) {
    int l = s.length() - 1, r = t.length() - 1, lstop = 0, rstop = 0;
    while (l >= 0 || r >= 0) {
      while (l >= 0) {
        if (s[l] == '#') {
          ++lstop;
        } else if (lstop) {
          --lstop;
        } else {
          break;
        }
        --l;
      }
      while (r >= 0) {
        if (t[r] == '#') {
          ++rstop;
        } else if (rstop) {
          --rstop;
        } else {
          break;
        }
        --r;
      }
      if (l < 0 && r < 0) {
        return true;
      }
      if (l >= 0 && r >= 0 && s[l] == t[r]) {
        --l;
        --r;
        continue;
      }
      return false;
    }
    return true;
  }
};
// @lc code=end
class Solution_2 {
public:
  bool backspaceCompare(string s, string t) {
    int l = changeStr(s), r = changeStr(t);
    return l == r && s.substr(0, l) == t.substr(0, r);
  }
  int changeStr(string &s) {
    int slow = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] != '#') {
        s[slow] = s[i];
        ++slow;
      } else if (slow > 0) {
        --slow;
      }
    }
    return slow;
  }
};