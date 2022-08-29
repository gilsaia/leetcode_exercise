/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    vector<int> res;
    while (l < r) {
      if (abs(nums[l]) > abs(nums[r])) {
        res.push_back(nums[l] * nums[l]);
        ++l;
      } else {
        res.push_back(nums[r] * nums[r]);
        --r;
      }
    }
    res.push_back(nums[l] * nums[l]);
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
