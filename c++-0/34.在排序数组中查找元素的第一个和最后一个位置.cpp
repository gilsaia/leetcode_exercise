/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.size() == 0) {
      return vector<int>{-1, -1};
    }
    int left = 0, right = nums.size(), mid;
    while (left < right) {
      mid = (left + right) / 2;
      if (nums[mid] >= target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    if (left >= nums.size() || nums[left] != target) {
      return vector<int>{-1, -1};
    }
    int left_res = left;
    left = 0, right = nums.size();
    while (left < right) {
      mid = (left + right) / 2;
      if (nums[mid] > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return vector<int>{left_res, right - 1};
  }
};
// @lc code=end
