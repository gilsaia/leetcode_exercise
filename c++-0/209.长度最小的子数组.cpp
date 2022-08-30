/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
      nums[i] += nums[i - 1];
    }
    nums.insert(nums.begin(), 0);
    int ans = 1000000;
    for (int i = 0; i < nums.size(); ++i) {
      int left = i, right = nums.size(), mid;
      while (left < right) {
        mid = (left + right) / 2;
        if ((nums[mid] - nums[i]) >= target) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      if (left != nums.size()) {
        ans = min(ans, left - i);
      }
    }
    if (ans == 1000000) {
      ans = 0;
    }
    return ans;
  }
};
// @lc code=end
class Solution_2 {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int left = 0, right = 0, temp_sum = 0, ans = 1000000;
    while (left < nums.size()) {
      if (temp_sum < target) {
        if (right < nums.size()) {
          temp_sum += nums[right];
          ++right;
        } else {
          break;
        }
      } else {
        ans = min(ans, right - left);
        temp_sum -= nums[left];
        ++left;
      }
    }
    if (ans == 1000000) {
      ans = 0;
    }
    return ans;
  }
};