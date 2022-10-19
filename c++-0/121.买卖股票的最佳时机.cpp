/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    vector<vector<int>> dp(2, vector<int>(prices.size(), 0));
    dp[0][0] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      dp[0][i] = max(dp[0][i - 1], -prices[i]);
      dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + prices[i]);
    }
    return dp[1][prices.size() - 1];
  }
};
// @lc code=end
