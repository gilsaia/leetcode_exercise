/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int x = 0, y = 0, now = 1, left = 0, right = n - 1, up = 0, down = n - 1,
        dir = 0;
    for (int i = 0; i < n * n; ++i) {
      ans[x][y] = now;
      switch (dir) {
      case 0:
        ++y;
        if (y == right) {
          dir = 1;
          ++up;
        }
        break;
      case 1:
        ++x;
        if (x == down) {
          dir = 2;
          --right;
        }
        break;
      case 2:
        --y;
        if (y == left) {
          dir = 3;
          --down;
        }
        break;
      case 3:
        --x;
        if (x == up) {
          dir = 0;
          ++left;
        }
        break;
      }
      ++now;
    }
    return ans;
  }
};
// @lc code=end
