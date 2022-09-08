/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <deque>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> ans;
    deque<pair<int, int>> que;
    for (int i = 0; i < k; ++i) {
      insert(que, nums[i], i);
    }
    ans.push_back(que.front().first);
    for (int i = k; i < nums.size(); ++i) {
      if (que.front().second <= (i - k)) {
        que.pop_front();
      }
      insert(que, nums[i], i);
      ans.push_back(que.front().first);
    }
    return ans;
  }
  void insert(deque<pair<int, int>> &que, int &ele, int &i) {
    while (!que.empty()) {
      if (ele > que.back().first) {
        que.pop_back();
      } else {
        break;
      }
    }
    que.push_back(make_pair(ele, i));
  }
};
// @lc code=end
