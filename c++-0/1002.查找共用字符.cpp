/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<string> commonChars(vector<string> &words) {
    unordered_map<char, int> hash, tmp;
    for (char &c : words[0]) {
      hash[c]++;
    }
    for (int i = 1; i < words.size(); ++i) {
      tmp.clear();
      for (char &c : words[i]) {
        tmp[c]++;
      }
      for (auto &iter : hash) {
        hash[iter.first] = min(tmp[iter.first], iter.second);
      }
    }
    vector<string> ans;
    for (auto &iter : hash) {
      for (int i = 0; i < iter.second; ++i) {
        string a;
        a += iter.first;
        ans.push_back(a);
      }
    }
    return ans;
  }
};
// @lc code=end
