/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> hash;
    for (char &c : s) {
      hash[c]++;
    }
    for (char &c : t) {
      hash[c]--;
    }
    for (auto &ele : hash) {
      if (ele.second != 0) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
