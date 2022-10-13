/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    int count[5];
    count[1] = count[2] = count[4] = 0;
    for (int &check : bills) {
      int ind = check / 5;
      if (ind == 1) {
        count[1]++;
      } else if (ind == 2) {
        if (count[1] == 0) {
          return false;
        }
        count[1]--;
        count[2]++;
      } else {
        if (count[2] > 0 && count[1] > 0) {
          --count[2];
          --count[1];
        } else if (count[1] >= 3) {
          count[1] -= 3;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};
// @lc code=end
