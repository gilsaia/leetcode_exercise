/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool validMountainArray(vector<int> &arr) {
    if (arr.size() < 3 || arr[1] < arr[0]) {
      return false;
    }
    int dir = 1;
    for (int i = 1; i < arr.size(); ++i) {
      if (arr[i] == arr[i - 1]) {
        return false;
      }
      if (dir) {
        if (arr[i] > arr[i - 1]) {
          continue;
        } else {
          dir = 0;
        }
      } else {
        if (arr[i] > arr[i - 1]) {
          return false;
        }
      }
    }
    return dir == 0;
  }
};
// @lc code=end
