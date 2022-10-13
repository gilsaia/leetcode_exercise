/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int jump(vector<int> &nums) {
    int ans = 0;
    int maxind = 0;
    vector<int> used(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i) {
      int tmpind = i + nums[i];
      for (int j = maxind + 1; j < nums.size() && j <= tmpind; ++j) {
        used[j] = used[i] + 1;
      }
      maxind = max(maxind, tmpind);
    }
    return used[nums.size() - 1];
  }
};
// @lc code=end
