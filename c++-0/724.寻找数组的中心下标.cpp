/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    vector<int> res(nums.size(), 0);
    res[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      res[i] = res[i - 1] + nums[i];
    }
    int sum = res[nums.size() - 1];
    if ((sum - nums[0]) == 0) {
      return 0;
    }
    for (int i = 1; i < nums.size(); ++i) {
      if ((sum - nums[i]) == res[i - 1] * 2) {
        return i;
      }
    }
    return -1;
  }
};
// @lc code=end
