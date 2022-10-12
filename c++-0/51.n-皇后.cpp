/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void dfs(vector<vector<string>> &res, vector<string> &path, vector<int> &used,
           int &n, int floor) {
    if (floor == n) {
      res.push_back(path);
      return;
    }
    string start(n, '.');
    for (int i = 0; i < n; ++i) {
      bool can = true;
      for (int j = 0; j < floor; ++j) {
        if (used[j] == i || abs(i - used[j]) == floor - j) {
          can = false;
          break;
        }
      }
      if (!can) {
        continue;
      }
      start[i] = 'Q';
      path.push_back(start);
      used.push_back(i);
      dfs(res, path, used, n, floor + 1);
      start[i] = '.';
      used.pop_back();
      path.pop_back();
    }
  }
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> path;
    vector<int> used;
    dfs(res, path, used, n, 0);
    return res;
  }
};
// @lc code=end
