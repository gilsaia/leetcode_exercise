/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
    int ans = 0;
    for (int i = 0; i < nums1.size(); ++i) {
      if (nums1[i] == nums2[0]) {
        dp[i][0] = 1;
        ans = 1;
      }
    }
    for (int i = 0; i < nums2.size(); ++i) {
      if (nums2[i] == nums1[0]) {
        dp[0][i] = 1;
        ans = 1;
      }
    }
    for (int i = 1; i < nums1.size(); ++i) {
      for (int j = 1; j < nums2.size(); ++j) {
        if (nums1[i] == nums2[j]) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
          ans = max(ans, dp[i][j]);
        }
      }
    }
    return ans;
  }
};
// @lc code=end
