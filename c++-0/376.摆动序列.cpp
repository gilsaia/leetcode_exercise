/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int wiggleMaxLength(vector<int> &nums) {
    if (nums.size() < 2) {
      return 1;
    }
    if (nums.size() == 2) {
      if (nums[0] != nums[1]) {
        return 2;
      } else {
        return 1;
      }
    }
    int res = 0;
    int tmpres = 0;
    int dir = 1;
    for (int ind = 0; ind < nums.size(); ++ind) {
      int next = ind + 1;
      if (dir == 1) {
        while (next < nums.size() && nums[next] >= nums[ind]) {
          ind = next;
          ++next;
        }
      } else {
        while (next < nums.size() && nums[next] <= nums[ind]) {
          ind = next;
          ++next;
        }
      }
      if (ind < nums.size()) {
        ++tmpres;
        dir *= -1;
      }
    }
    res = max(res, tmpres);
    dir = -1;
    tmpres = 0;
    for (int ind = 0; ind < nums.size(); ++ind) {
      int next = ind + 1;
      if (dir == 1) {
        while (next < nums.size() && nums[next] >= nums[ind]) {
          ind = next;
          ++next;
        }
      } else {
        while (next < nums.size() && nums[next] <= nums[ind]) {
          ind = next;
          ++next;
        }
      }
      if (ind < nums.size()) {
        ++tmpres;
        dir *= -1;
      }
    }
    res = max(res, tmpres);
    return res;
  }
};
// @lc code=end
