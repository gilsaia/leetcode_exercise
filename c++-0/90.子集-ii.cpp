/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void dfs(vector<vector<int>> &res, vector<int> &path, vector<int> &nums,
           int start) {
    if (start == nums.size()) {
      res.push_back(path);
      return;
    }
    int pre = -20;
    path.push_back(nums[start]);
    dfs(res, path, nums, start + 1);
    path.pop_back();
    int i = start + 1;
    while (i < nums.size()) {
      if (nums[i] == nums[start]) {
        i++;
      } else {
        break;
      }
    }
    dfs(res, path, nums, i);
    return;
  }
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> path;
    sort(nums.begin(), nums.end());
    dfs(res, path, nums, 0);
    return res;
  }
};
// @lc code=end
