/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
#include <algorithm>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  string reverseStr(string s, int k) {
    int count = s.size() / k;
    for (int i = 0; i < count; ++i) {
      reverse(s.begin() + i * k, s.begin() + (i + 1) * k);
      ++i;
    }
    if (s.size() % k && !(count % 2)) {
      reverse(s.begin() + k * count, s.end());
    }
    return s;
  }
};
// @lc code=end
