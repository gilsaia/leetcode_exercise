/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    vector<int> zerodig(strs.size(), 0);
    vector<int> onedig(strs.size(), 0);
    for (int i = 0; i < strs.size(); ++i) {
      for (char &c : strs[i]) {
        if (c == '0') {
          zerodig[i]++;
        } else {
          onedig[i]++;
        }
      }
    }
    vector<int> dp(128 * 128, 0);
    for (int i = 0; i < strs.size(); ++i) {
      int tmp = onedig[i] * 128 + zerodig[i];
      for (int j = 128 * 128 - 1; j >= tmp; --j) {
        if (j % 128 < zerodig[i]) {
          continue;
        }
        dp[j] = max(dp[j], dp[j - tmp] + 1);
      }
    }
    return dp[n * 128 + m];
  }
};
// @lc code=end
