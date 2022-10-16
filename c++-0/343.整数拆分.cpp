/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int integerBreak(int n) {
    vector<int> dp(60, 0);
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (i == n && j == 0) {
          continue;
        }
        dp[i] = max(dp[i], dp[j] * (i - j));
      }
    }
    return dp[n];
  }
};
// @lc code=end
