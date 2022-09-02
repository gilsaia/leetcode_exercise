/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> hash;
    for (auto &c : ransomNote) {
      hash[c]--;
    }
    for (auto &c : magazine) {
      hash[c]++;
    }
    for (auto &ele : hash) {
      if (ele.second < 0) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
