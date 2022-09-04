/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        long long tmp = (long long)target - nums[i] - nums[j];
        int left = j + 1, right = nums.size() - 1;
        while (left < right) {
          if ((long long)(nums[left] + nums[right]) == tmp) {
            ans.push_back({nums[i], nums[j], nums[left], nums[right]});
            ++left;
            while (left < right && nums[left] == nums[left - 1]) {
              ++left;
            }
          } else if ((long long)(nums[left] + nums[right]) > tmp) {
            --right;
          } else {
            ++left;
          }
        }
        while ((j + 1) < nums.size() && nums[j] == nums[j + 1]) {
          ++j;
        }
      }
      while ((i + 1) < nums.size() && nums[i] == nums[i + 1]) {
        ++i;
      }
    }
    return ans;
  }
};
// @lc code=end
