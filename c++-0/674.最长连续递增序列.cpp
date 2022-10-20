/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int findLengthOfLCIS(vector<int> &nums) {
    vector<int> dp(nums.size(), 1);
    int ans = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        dp[i] = max(dp[i], dp[i - 1] + 1);
        ans = max(ans, dp[i]);
      }
    }
    return ans;
  }
};
// @lc code=end
