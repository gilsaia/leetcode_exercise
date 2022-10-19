/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
  int rob(vector<int> &nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (i > 1) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
      } else {
        dp[i] = max(nums[i], dp[i - 1]);
      }
    }
    return dp.back();
  }
};
// @lc code=end
