/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include <map>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    map<char, int> hash;
    for (char &c : p) {
      hash[c]++;
    }
    map<char, int> cmp;
    vector<int> ans;
    if (s.size() < p.size()) {
      return ans;
    }
    for (int i = 0; i < p.size(); ++i) {
      cmp[s[i]]++;
    }
    if (hash == cmp) {
      ans.push_back(0);
    }
    for (int i = p.size(); i < s.size(); ++i) {
      cmp[s[i]]++;
      int tmp = i - p.size();
      cmp[s[tmp]]--;
      if (cmp[s[tmp]] == 0) {
        cmp.erase(s[tmp]);
      }
      if (hash == cmp) {
        ans.push_back(tmp + 1);
      }
    }
    return ans;
  }
};
// @lc code=end
