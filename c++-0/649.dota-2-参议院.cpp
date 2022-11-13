/*
 * @lc app=leetcode.cn id=649 lang=cpp
 *
 * [649] Dota2 参议院
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  string predictPartyVictory(string senate) {
    string round = senate, next_round;
    int wait[2]{0, 0};
    while (true) {
      next_round.clear();
      int count[2]{0, 0};
      for (char &s : round) {
        if (s == 'R') {
          ++count[0];
          if (wait[0]) {
            --wait[0];
          } else {
            ++wait[1];
            next_round += 'R';
          }
        } else {
          ++count[1];
          if (wait[1]) {
            --wait[1];
          } else {
            ++wait[0];
            next_round += 'D';
          }
        }
      }
      round = next_round;
      if (count[0] == 0 || count[1] == 0) {
        break;
      }
    }
    if (round[0] == 'R') {
      return "Radiant";
    } else {
      return "Dire";
    }
  }
};
// @lc code=end
