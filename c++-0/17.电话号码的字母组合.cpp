/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  string hash[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  void dfs(vector<string> &res, string &path, int index, string &digits) {
    if (index == digits.length()) {
      res.push_back(path);
      return;
    }
    for (char &c : hash[digits[index] - '2']) {
      path += c;
      dfs(res, path, index + 1, digits);
      path.pop_back();
    }
    return;
  }
  vector<string> letterCombinations(string digits) {
    vector<string> res;
    string path;
    if (digits.empty()) {
      return res;
    }
    dfs(res, path, 0, digits);
    return res;
  }
};
// @lc code=end
