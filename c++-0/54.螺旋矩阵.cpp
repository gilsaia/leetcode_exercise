/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ans;
    int m = matrix.size(), n = matrix[0].size();
    int x = 0, y = 0, left = 0, right = n - 1, up = 0, down = m - 1, now = 0,
        dir = y == right ? 1 : 0;
    while (now < m * n) {
      ans.push_back(matrix[x][y]);
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
