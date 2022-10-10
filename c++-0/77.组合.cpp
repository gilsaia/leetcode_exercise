/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void dfs(vector<vector<int>> &res, vector<int> &path, int start, int n,
           int k) {
    path.push_back(start);
    if (k == 0) {
      res.push_back(path);
      return;
    }
    for (int i = start + 1; i <= n; ++i) {
      dfs(res, path, i, n, k - 1);
      path.pop_back();
    }
    return;
  }
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> path;
    for (int i = 1; i <= n; ++i) {
      dfs(res, path, i, n, k - 1);
      path.pop_back();
    }
    return res;
  }
};
// @lc code=end
