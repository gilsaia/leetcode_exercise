/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void dfs(vector<vector<int>> &res, vector<int> &path, vector<int> &candidates,
           int index, int target) {
    if (target <= 0) {
      if (target == 0) {
        res.push_back(path);
      }
      return;
    }
    int prev;
    for (int i = index; i < candidates.size();) {
      prev = candidates[i];
      path.push_back(candidates[i]);
      dfs(res, path, candidates, i + 1, target - candidates[i]);
      path.pop_back();
      while (i < candidates.size() && candidates[i] == prev) {
        ++i;
      }
    }
    return;
  }
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    dfs(res, path, candidates, 0, target);
    return res;
  }
};
// @lc code=end
