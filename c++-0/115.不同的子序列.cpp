/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  int numDistinct(string s, string t) {
    vector<vector<unsigned long long>> dp(
        s.size() + 1, vector<unsigned long long>(t.size() + 1, 0));
    for (int i = 0; i < s.size(); ++i) {
      dp[i][0] = 1;
      for (int j = 0; j < t.size(); ++j) {
        dp[i + 1][j + 1] = dp[i][j + 1];
        if (s[i] == t[j]) {
          dp[i + 1][j + 1] += dp[i][j];
        }
      }
    }
    return dp[s.size()][t.size()];
  }
};
// @lc code=end
