/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  static bool cmp(vector<int> &a, vector<int> &b) {
    if (a[0] == b[0]) {
      return a[1] < b[1];
    }
    return a[0] < b[0];
  }
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    vector<vector<int>> res;
    int ind = 0;
    while (ind < intervals.size()) {
      int right = intervals[ind][1];
      int next = ind + 1;
      while (next < intervals.size() && intervals[next][0] <= right) {
        right = max(right, intervals[next][1]);
        ++next;
      }
      res.push_back({intervals[ind][0], right});
      ind = next;
    }
    return res;
  }
};
// @lc code=end
