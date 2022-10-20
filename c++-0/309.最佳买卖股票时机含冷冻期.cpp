/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0][0] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      if (i > 1) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i]);
      } else {
        dp[i][0] = max(dp[i - 1][0], -prices[i]);
      }
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[prices.size() - 1][1];
  }
};
// @lc code=end
