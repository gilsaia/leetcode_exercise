/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void dfs(vector<string> &res, string &path, string &s, int cnt, int start) {
    if (start == s.size()) {
      if (cnt == 4) {
        path.pop_back();
        res.push_back(path);
        path += '.';
      }
      return;
    }
    int sum = 0;
    bool iszero = s[start] == '0';
    for (int i = start; i < (start + 3) && i < s.size(); ++i) {
      sum *= 10;
      sum += s[i] - '0';
      if (sum > 255) {
        break;
      }
      path += s.substr(start, i - start + 1);
      path += '.';
      dfs(res, path, s, cnt + 1, i + 1);
      path.erase(path.end() - (i - start + 2), path.end());
      if (iszero) {
        break;
      }
    }
    return;
  }
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string path;
    dfs(res, path, s, 0, 0);
    return res;
  }
};
// @lc code=end
