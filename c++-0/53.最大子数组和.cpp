/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    vector<int> addsum;
    addsum.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i) {
      addsum.push_back(addsum[i - 1] + nums[i]);
    }
    int res = addsum[0];
    int minleft = 0, maxright = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (addsum[i] >= addsum[maxright]) {
        maxright = i;
      }
      if (addsum[i] < addsum[minleft]) {
        minleft = i;
      }
      if (maxright >= minleft) {
        res = max(res, addsum[maxright] - addsum[minleft]);
      }
    }
  }
};
// @lc code=end
