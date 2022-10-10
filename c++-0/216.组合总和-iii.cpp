/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void dfs(vector<vector<int>> &res, vector<int> &path, int start, int n,
           int &k) {
    if (path.size() == k) {
      if (n == 0) {
        res.push_back(path);
      }
      return;
    }
    for (int i = start; i <= 9; ++i) {
      path.push_back(i);
      dfs(res, path, i + 1, n - i, k);
      path.pop_back();
    }
    return;
  }
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> path;
    dfs(res, path, 1, n, k);
    return res;
  }
};
// @lc code=end
