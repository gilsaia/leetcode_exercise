/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int numSquares(int n) {
    vector<int> choices(100, 0);
    for (int i = 0; i < 100; ++i) {
      choices[i] = (i + 1) * (i + 1);
    }
    vector<int> dp(10002, 1000002);
    dp[0] = 0;
    for (int i = 0; i < 100; ++i) {
      if (choices[i] > n) {
        break;
      }
      for (int j = choices[i]; j <= n; ++j) {
        dp[j] = min(dp[j], dp[j - choices[i]] + 1);
      }
    }
    return dp[n];
  }
};
// @lc code=end
