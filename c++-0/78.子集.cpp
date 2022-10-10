/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
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
    dfs(res, path, nums, start + 1);
    path.push_back(nums[start]);
    dfs(res, path, nums, start + 1);
    path.pop_back();
  }
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> path;
    dfs(res, path, nums, 0);
    return res;
  }
};
// @lc code=end
