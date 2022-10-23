/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
    for (int i = 0; i < s.size(); ++i) {
      dp[i][i] = 1;
    }
    for (int i = 1; i < s.size(); ++i) {
      for (int j = 0; j < s.size() - i; ++j) {
        if (s[j] == s[j + i]) {
          dp[j][j + i] = dp[j + 1][j + i - 1] + 2;
        } else {
          dp[j][j + i] = max(dp[j][j + i - 1], dp[j + 1][j + i]);
        }
      }
    }
    return dp[0][s.size() - 1];
  }
};
// @lc code=end
