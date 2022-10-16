/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
  int numTrees(int n) {
    int dp[20];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      dp[i] = 0;
      for (int j = 0; j < i; ++j) {
        dp[i] += dp[j] * dp[i - j - 1];
      }
    }
    return dp[n];
  }
};
// @lc code=end
