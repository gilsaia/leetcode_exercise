/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换II
 */
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int change(int amount, vector<int> &coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < coins.size(); ++i) {
      for (int j = 0; j < amount + 1 - coins[i]; ++j) {
        dp[j + coins[i]] += dp[j];
      }
    }
    return dp[amount];
  }
};
// @lc code=end
