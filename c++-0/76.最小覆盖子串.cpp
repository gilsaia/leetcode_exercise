/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> check;
    for (char &c : t) {
      check[c]++;
    }
    int correct = check.size(), success = 0, left = 0, right = 0, ans_pos = -1,
        ans_len = 1000000;
    while (right < s.size()) {
      while (right < s.size() && success < correct) {
        if (check.find(s[right]) != check.end()) {
          --check[s[right]];
          if (check[s[right]] == 0) {
            ++success;
          }
        }
        ++right;
      }
      while (left < s.size() && success >= correct) {
        if (check.find(s[left]) != check.end()) {
          if (check[s[left]] == 0) {
            if ((right - left) < ans_len) {
              ans_pos = left;
              ans_len = right - left;
            }
            --success;
          }
          ++check[s[left]];
        }
        ++left;
      }
    }
    if (ans_len == 1000000) {
      return "";
    }
    return s.substr(ans_pos, ans_len);
  }
};
// @lc code=end
