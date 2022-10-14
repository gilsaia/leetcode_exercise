/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  static bool cmp(vector<int> &a, vector<int> &b) {
    if (a[1] == b[1]) {
      return a[0] < b[0];
    }
    return a[1] < b[1];
  }
  int findMinArrowShots(vector<vector<int>> &points) {
    sort(points.begin(), points.end(), cmp);
    int res = 0;
    int ind = 0;
    while (ind < points.size()) {
      ++res;
      int point = points[ind][1];
      int next = ind + 1;
      while (next < points.size() && points[next][0] <= point) {
        ++next;
      }
      ind = next;
    }
    return res;
  }
};
// @lc code=end
