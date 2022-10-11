/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void dfs(vector<vector<int>> &res, vector<int> &path, vector<int> &nums,
           vector<int> &used) {
    if (path.size() == nums.size()) {
      res.push_back(path);
      return;
    }
    int pre = -20;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == pre || used[i]) {
        continue;
      }
      pre = nums[i];
      used[i] = 1;
      path.push_back(nums[i]);
      dfs(res, path, nums, used);
      used[i] = 0;
      path.pop_back();
    }
  }
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> path;
    vector<int> used(nums.size(), 0);
    dfs(res, path, nums, used);
    return res;
  }
};
// @lc code=end
