/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    unordered_map<int, int> hash;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int left = i + 1, right = nums.size() - 1, tmp = -nums[i];
      while (left < right) {
        if ((nums[left] + nums[right]) == tmp) {
          ans.push_back({nums[i], nums[left], nums[right]});
          ++left;
          while (left < right && nums[left] == nums[left - 1]) {
            ++left;
          }
        }
        if ((nums[left] + nums[right]) > tmp) {
          --right;
        } else {
          ++left;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
