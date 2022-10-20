/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
    for (int i = 0; i < nums1.size(); ++i) {
      for (int j = 0; j < nums2.size(); ++j) {
        if (nums1[i] == nums2[j]) {
          dp[i + 1][j + 1] = dp[i][j] + 1;
        }
        dp[i + 1][j + 1] =
            max(dp[i + 1][j + 1], max(dp[i][j + 1], dp[i + 1][j]));
      }
    }
    return dp[nums1.size()][nums2.size()];
  }
};
// @lc code=end
