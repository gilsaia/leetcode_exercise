/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
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
    for (int i = index; i < candidates.size(); ++i) {
      path.push_back(candidates[i]);
      dfs(res, path, candidates, i, target - candidates[i]);
      path.pop_back();
    }
    return;
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> path;
    dfs(res, path, candidates, 0, target);
    return res;
  }
};
// @lc code=end
