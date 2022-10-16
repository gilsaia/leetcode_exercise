/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int monotoneIncreasingDigits(int n) {
    vector<int> digits;
    int ori = n;
    while (n) {
      digits.push_back(n % 10);
      n /= 10;
    }
    if (digits.size() < 2) {
      return ori;
    }
    for (int i = 1; i < digits.size(); ++i) {
      if (digits[i] > digits[i - 1]) {
        for (int j = 0; j < i; ++j) {
          digits[j] = 9;
        }
        digits[i]--;
      }
    }
    int res = 0;
    for (int i = digits.size() - 1; i >= 0; --i) {
      res *= 10;
      res += digits[i];
    }
    return res;
  }
};
// @lc code=end
