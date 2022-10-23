/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
  int countSubstrings(string s) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      ans++;
      dp[i][i] = 1;
    }
    for (int i = 1; i < s.size(); ++i) {
      for (int j = 0; j < s.size() - i; ++j) {
        if (s[j] == s[j + i]) {
          if (i < 2) {
            dp[j][j + i] = 1;
            ++ans;
          } else {
            dp[j][j + i] = dp[j + 1][j + i - 1];
            ans += dp[j][j + i];
          }
        } else {
          dp[j][j + i] = 0;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
