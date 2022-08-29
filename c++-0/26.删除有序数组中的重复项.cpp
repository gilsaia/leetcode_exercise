/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int slow = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[slow]) {
        continue;
      }
      ++slow;
      nums[slow] = nums[i];
    }
    return slow + 1;
  }
};
// @lc code=end
