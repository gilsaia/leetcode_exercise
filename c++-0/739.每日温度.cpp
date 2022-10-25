/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<int> sta;
    int maxtemp = 0;
    vector<int> ans(temperatures.size(), 0);
    sta.push(0);
    for (int i = 1; i < temperatures.size(); ++i) {
      if (temperatures[i] < temperatures[sta.top()]) {
        sta.push(i);
      } else if (temperatures[i] == temperatures[sta.top()]) {
        sta.push(i);
      } else {
        while (!sta.empty() && temperatures[i] > temperatures[sta.top()]) {
          ans[sta.top()] = i - sta.top();
          sta.pop();
        }
        sta.push(i);
      }
    }
    return ans;
  }
};
// @lc code=end
