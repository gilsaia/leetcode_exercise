/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int inds = 0;
    int res = 0;
    for (int i = 0; i < g.size(); ++i) {
      while (inds < s.size() && g[i] > s[inds]) {
        ++inds;
      }
      if (inds >= s.size()) {
        break;
      }
      res++;
      inds++;
    }
    return res;
  }
};
// @lc code=end
