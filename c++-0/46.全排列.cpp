/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void dfs(vector<vector<int>> &res, vector<int> &path, vector<int> &nums,
           vector<int> &used, int &n) {
    if (path.size() == n) {
      res.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (!used[i]) {
        used[i] = 1;
        path.push_back(nums[i]);
        dfs(res, path, nums, used, n);
        path.pop_back();
        used[i] = 0;
      }
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> path;
    vector<int> used(nums.size(), 0);
    int size = nums.size();
    dfs(res, path, nums, used, size);
    return res;
  }
};
// @lc code=end
