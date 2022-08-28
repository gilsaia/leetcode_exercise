/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int left = 0, right = nums.size();
    while (left < right) {
      if (nums[left] == val) {
        swap(nums[left], nums[right - 1]);
        --right;
      } else {
        ++left;
      }
    }
    return right;
  };
};
// @lc code=end
class Solution_2 {
public:
  int removeElement(vector<int> &nums, int val) {
    int slow = 0, len = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != val) {
        nums[slow] = nums[i];
        ++slow;
      } else {
        --len;
      }
    }
    return len;
  };
};