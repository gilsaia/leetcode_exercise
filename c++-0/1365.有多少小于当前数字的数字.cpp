/*
 * @lc app=leetcode.cn id=1365 lang=cpp
 *
 * [1365] 有多少小于当前数字的数字
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    vector<int> hash(120, 0);
    for (int &ele : nums) {
      hash[ele]++;
    }
    vector<int> cumsum(120, 0);
    for (int i = 1; i <= 100; ++i) {
      cumsum[i] = cumsum[i - 1] + hash[i - 1];
    }
    vector<int> ans(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i) {
      ans[i] = cumsum[nums[i]];
    }
    return ans;
  }
};
// @lc code=end
