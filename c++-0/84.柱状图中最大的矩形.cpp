/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int ans = 0;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    stack<int> sta;
    for (int i = 0; i < heights.size(); ++i) {
      ans = max(ans, heights[i]);
      if (sta.empty()) {
        sta.push(i);
      }
      while (!sta.empty() && heights[i] < heights[sta.top()]) {
        int oldheight = heights[sta.top()];
        sta.pop();
        ans = max(ans, oldheight * (i - sta.top() - 1));
      }
      sta.push(i);
    }
    return ans;
  }
};
// @lc code=end
