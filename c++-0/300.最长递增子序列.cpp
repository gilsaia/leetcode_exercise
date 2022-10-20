/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include <vector>
#include <list>
using namespace std;
// @lc code=start
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> dp(nums.size() + 1, 1000005);
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j <= ans; ++j) {
        if (nums[i] <= dp[j]) {
          dp[j] = nums[i];
          ans = max(ans, j + 1);
          break;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
