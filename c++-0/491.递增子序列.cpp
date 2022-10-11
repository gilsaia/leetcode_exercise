/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void dfs(vector<vector<int>> &res, vector<int> &path, vector<int> &nums,
           vector<int> &count, int start) {
    if (start == nums.size()) {
      if (path.size() > 1) {
        res.push_back(path);
      }
      return;
    }
    if (path.empty() || nums[start] >= path.back()) {
      int pos = count.back() + 1;
      bool find = false;
      for (int i = pos; i < start; ++i) {
        if (nums[i] == nums[start]) {
          find = true;
          break;
        }
      }
      if (!find) {
        path.push_back(nums[start]);
        count.push_back(start);
        dfs(res, path, nums, count, start + 1);
        path.pop_back();
        count.pop_back();
      }
    }
    int i = start + 1;
    while (i < nums.size()) {
      if (nums[i] == nums[start]) {
        ++i;
      } else {
        break;
      }
    }
    dfs(res, path, nums, count, i);
  }
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> path;
    vector<int> count;
    count.push_back(-1);
    dfs(res, path, nums, count, 0);
    return res;
  }
};
// @lc code=end
