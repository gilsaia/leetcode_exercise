/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  static bool cmp(vector<int> &a, vector<int> &b) {
    if (a[1] == b[1]) {
      return a[0] > b[0];
    }
    return a[1] < b[1];
  }
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    int res = 0;
    int ind = 0;
    sort(intervals.begin(), intervals.end(), cmp);
    while (ind < intervals.size()) {
      int nowright = intervals[ind][1];
      int next = ind + 1;
      while (next < intervals.size() && intervals[next][0] < nowright) {
        ++res;
        ++next;
      }
      ind = next;
    }
    return res;
  }
};
// @lc code=end
