/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, int> hashs, hasht;
    int inds, indt;
    for (int i = 0; i < s.size(); ++i) {
      if (!hashs.count(s[i])) {
        hashs[s[i]] = hashs.size();
      }
      inds = hashs[s[i]];
      if (!hasht.count(t[i])) {
        hasht[t[i]] = hasht.size();
      }
      indt = hasht[t[i]];
      if (inds != indt) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
