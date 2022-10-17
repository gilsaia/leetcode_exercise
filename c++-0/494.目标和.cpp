/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    vector<vector<int>> dp(2, vector<int>(2020, 0));
    dp[1][1000] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      int ele = nums[i];
      for (int j = 0; j < ele; ++j) {
        dp[i % 2][j] = 0;
      }
      for (int j = ele; j <= 2000; ++j) {
        dp[i % 2][j] = dp[(i + 1) % 2][j - ele];
      }
      for (int j = 0; j <= 2000 - ele; ++j) {
        dp[i % 2][j] += dp[(i + 1) % 2][j + ele];
      }
    }
    return dp[(nums.size() - 1) % 2][target + 1000];
  }
};
// @lc code=end
