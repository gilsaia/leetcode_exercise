/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
  int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (int i = 0; i <= word2.size(); ++i) {
      dp[0][i] = i;
    }
    for (int i = 0; i < word1.size(); ++i) {
      dp[i + 1][0] = i + 1;
      for (int j = 0; j < word2.size(); ++j) {
        if (word1[i] == word2[j]) {
          dp[i + 1][j + 1] = dp[i][j];
        } else {
          dp[i + 1][j + 1] =
              min(dp[i][j] + 1, min(dp[i][j + 1] + 1, dp[i + 1][j] + 1));
        }
      }
    }
    return dp[word1.size()][word2.size()];
  }
};
// @lc code=end
