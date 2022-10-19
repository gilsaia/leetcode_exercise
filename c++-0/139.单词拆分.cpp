/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 0; j < wordDict.size(); ++j) {
        if (wordDict[j].size() > i || dp[i - wordDict[j].size()] == 0) {
          continue;
        }
        if (s.substr(i - wordDict[j].size(), wordDict[j].size()) ==
            wordDict[j]) {
          dp[i] = 1;
        }
      }
    }
    return dp[s.size()] == 1;
  }
};
// @lc code=end
