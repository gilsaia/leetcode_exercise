/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    vector<int> ans(nums.size(), -1);
    stack<int> sta;
    int index = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (sta.empty()) {
        sta.push(i);
        continue;
      }
      while (!sta.empty() && nums[i] > nums[sta.top()]) {
        ans[sta.top()] = nums[i];
        sta.pop();
      }
      sta.push(i);
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (sta.empty()) {
        sta.push(i);
        continue;
      }
      while (!sta.empty() && nums[i] > nums[sta.top()]) {
        ans[sta.top()] = nums[i];
        sta.pop();
      }
      sta.push(i);
    }
    return ans;
  }
};
// @lc code=end
