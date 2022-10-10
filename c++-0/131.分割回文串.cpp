/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int dp[20][20];
  void dfs(vector<vector<string>> &res, vector<string> &path, string &s,
           int start) {
    if (start == s.size()) {
      res.push_back(path);
      return;
    }
    for (int i = start; i < s.size(); ++i) {
      if (dp[start][i + 1]) {
        path.push_back(s.substr(start, i - start + 1));
        dfs(res, path, s, i + 1);
        path.pop_back();
      }
    }
    return;
  }
  vector<vector<string>> partition(string s) {
    for (int i = 0; i < s.size(); ++i) {
      dp[i][i] = 1;
      dp[i][i + 1] = 1;
    }
    for (int i = 2; i <= s.size(); ++i) {
      for (int j = 0; (i + j) <= s.size(); ++j) {
        int dj = j + 1, di = j + i - 1;
        if (dp[dj][di] && s[j] == s[di]) {
          dp[j][j + i] = 1;
        } else {
          dp[j][j + i] = 0;
        }
      }
    }
    vector<vector<string>> res;
    vector<string> path;
    dfs(res, path, s, 0);
    return res;
  }
};
// @lc code=end
