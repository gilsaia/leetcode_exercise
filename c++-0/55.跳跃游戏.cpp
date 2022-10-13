/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool canJump(vector<int> &nums) {
    int maxind = 0;
    int cur = 0;
    while (cur < nums.size() && cur <= maxind) {
      maxind = max(maxind, cur + nums[cur]);
      ++cur;
    }
    if ((maxind + 1) >= nums.size()) {
      return true;
    }
    return false;
  }
};
// @lc code=end
