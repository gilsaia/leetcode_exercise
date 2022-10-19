/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
  int rob(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    } else if (nums.size() == 2) {
      return max(nums[0], nums[1]);
    }
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size() - 1; ++i) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    int ans = dp[nums.size() - 2];
    vector<int> dp2(nums.size(), 0);
    dp2[0] = nums[1], dp2[1] = max(nums[1], nums[2]);
    for (int i = 3; i < nums.size(); ++i) {
      dp2[i - 1] = max(dp2[i - 2], dp2[i - 3] + nums[i]);
    }
    return max(ans, dp2[nums.size() - 2]);
  }
};
// @lc code=end
