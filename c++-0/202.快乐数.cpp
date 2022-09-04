/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> hash;
    while (!hash.count(n)) {
      if (n == 1) {
        return true;
      }
      hash.insert(n);
      int tmp = 0;
      while (n) {
        tmp += (n % 10) * (n % 10);
        n /= 10;
      }
      n = tmp;
    }
    return false;
  }
};
// @lc code=end
