/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool dfs(vector<vector<char>> &board, int block) {
    if (block == 9) {
      return true;
    }
    bool res = false;
    for (int i = 0; i < 9; ++i) {
      int dx = block / 3 * 3 + i / 3;
      int dy = block % 3 * 3 + i % 3;
      if (board[dx][dy] != '.') {
        continue;
      }
      for (int j = 0; j < 9; ++j) {
        bool can = true;
        for (int t = 0; t < 9; ++t) {
          int tx = block / 3 * 3 + t / 3;
          int ty = block % 3 * 3 + t % 3;
          if (board[tx][ty] - '1' == j) {
            can = false;
            break;
          }
          if (board[dx][t] - '1' == j) {
            can = false;
            break;
          }
          if (board[t][dy] - '1' == j) {
            can = false;
            break;
          }
        }
        if (!can) {
          continue;
        }
        board[dx][dy] = '1' + j;
        res = dfs(board, block);
        if (res) {
          break;
        }
        board[dx][dy] = '.';
      }
      if (res) {
        break;
      } else {
        return false;
      }
    }
    if (!res) {
      res = dfs(board, block + 1);
    }
    return res;
  }
  void solveSudoku(vector<vector<char>> &board) {
    dfs(board, 0);
    return;
  }
};
// @lc code=end
