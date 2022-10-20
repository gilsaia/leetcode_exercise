/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {
    if (prices.size() == 0 || k == 0) {
      return 0;
    }
    vector<int> dp(k * 2, 0);
    for (int i = 0; i < k; ++i) {
      dp[i * 2] = -prices[0];
    }
    for (int i = 1; i < prices.size(); ++i) {
      dp[0] = max(dp[0], -prices[i]);
      dp[1] = max(dp[1], dp[0] + prices[i]);
      for (int j = 1; j < k; ++j) {
        dp[j * 2] = max(dp[j * 2], dp[j * 2 - 1] - prices[i]);
        dp[j * 2 + 1] = max(dp[j * 2 + 1], dp[j * 2] + prices[i]);
      }
    }
    return dp[k * 2 - 1];
  }
};
// @lc code=end
