/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int allsum = 0;
    for (int &ele : nums) {
      allsum += ele;
    }
    if (allsum % 2) {
      return false;
    }
    int target = allsum / 2;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = target; j >= 0; --j) {
        if (nums[i] > j) {
          break;
        }
        if (dp[j - nums[i]]) {
          dp[j] = dp[j - nums[i]] + 1;
        }
      }
    }
    return dp[target] != 0;
  }
};
// @lc code=end
