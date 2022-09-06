/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int strStr(string haystack, string needle) {
    vector<int> next(needle.size(), -1);
    int i = 1, j = -1;
    while (i < needle.size()) {
      while (j >= 0 && needle[i] != needle[j + 1]) {
        j = next[j];
      }
      if (needle[i] == needle[j + 1]) {
        ++j;
      }
      next[i] = j;
      ++i;
    }
    j = -1;
    for (int i = 0; i < haystack.size(); ++i) {
      while (j >= 0 && haystack[i] != needle[j + 1]) {
        j = next[j];
      }
      if (haystack[i] == needle[j + 1]) {
        ++j;
      }
      if (j == (needle.size() - 1)) {
        return i - needle.size() + 1;
      }
    }
    return -1;
  }
};
// @lc code=end
