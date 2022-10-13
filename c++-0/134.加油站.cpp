/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int gassu = 0, costsu = 0, cur = 0, minval = 0, ans = 0;
    for (int i = 0; i < gas.size(); ++i) {
      gassu += gas[i];
      costsu += cost[i];
      cur += gas[i];
      cur -= cost[i];
      if (cur < minval) {
        ans = (i + 1) % gas.size();
        minval = cur;
      }
    }
    if (gassu >= costsu) {
      return ans;
    } else {
      return -1;
    }
  }
};
// @lc code=end
