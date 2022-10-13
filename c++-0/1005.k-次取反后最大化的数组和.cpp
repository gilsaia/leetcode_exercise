/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int largestSumAfterKNegations(vector<int> &nums, int k) {
    int ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      if (k > 0 && nums[i] < 0) {
        nums[i] = -nums[i];
        --k;
      }
    }
    if (k % 2) {
      sort(nums.begin(), nums.end());
      nums[0] = -nums[0];
    }
    for (int i = 0; i < nums.size(); ++i) {
      ans += nums[i];
    }
    return ans;
  }
};
// @lc code=end
