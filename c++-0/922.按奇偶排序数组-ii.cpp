/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> sortArrayByParityII(vector<int> &nums) {
    int i = 0, j = 1;
    while (j < nums.size()) {
      while (i < nums.size() && !(nums[i] % 2)) {
        i += 2;
      }
      while (j < nums.size() && nums[j] % 2) {
        j += 2;
      }
      if (j < nums.size()) {
        swap(nums[i], nums[j]);
      }
    }
    return nums;
  }
};
// @lc code=end
