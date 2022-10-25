/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
  int trap(vector<int> &height) {
    int ans = 0;
    stack<int> sta;
    for (int i = 0; i < height.size(); ++i) {
      if (sta.empty()) {
        if (height[i] != 0) {
          sta.push(i);
        }
        continue;
      }
      while (!sta.empty() && height[i] > height[sta.top()]) {
        int oldheight = height[sta.top()];
        sta.pop();
        if (sta.empty()) {
          break;
        }
        int newheight = min(height[sta.top()], height[i]);
        ans += (newheight - oldheight) * (i - sta.top() - 1);
      }
      sta.push(i);
    }
    return ans;
  }
};
// @lc code=end
