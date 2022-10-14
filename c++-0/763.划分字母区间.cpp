/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> partitionLabels(string s) {
    vector<int> hash(30, 0);
    for (int i = 0; i < s.size(); ++i) {
      hash[s[i] - 'a'] = i + 1;
    }
    vector<int> res;
    int cur = 0;
    while (cur < s.size()) {
      int right = hash[s[cur] - 'a'];
      int ind = cur + 1;
      while (ind < right) {
        right = max(right, hash[s[ind] - 'a']);
        ++ind;
      }
      res.push_back(ind - cur);
      cur = ind;
    }
    return res;
  }
};
// @lc code=end
