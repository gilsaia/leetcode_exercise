/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ans;
    map<string, int> hash;
    for (string &s : strs) {
      string tmp = s;
      sort(tmp.begin(), tmp.end());
      if (hash.count(tmp)) {
        ans[hash[tmp]].push_back(s);
      } else {
        vector<string> res{s};
        hash[tmp] = ans.size();
        ans.push_back(res);
      }
    }
    return ans;
  }
};
// @lc code=end
class Solution_2 {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ans;
    vector<map<char, int>> hashvec;
    for (string &s : strs) {
      map<char, int> hash;
      for (char &c : s) {
        hash[c]++;
      }
      bool find = false;
      for (int i = 0; i < hashvec.size(); ++i) {
        if (hash == hashvec[i]) {
          ans[i].push_back(s);
          find = true;
          break;
        }
      }
      if (!find) {
        hashvec.push_back(hash);
        vector<string> tmp{s};
        ans.push_back(tmp);
      }
    }
    return ans;
  }
};