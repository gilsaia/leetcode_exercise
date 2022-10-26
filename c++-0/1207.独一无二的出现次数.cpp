/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> hash;
    for (int &ele : arr) {
      hash[ele]++;
    }
    unordered_map<int, int> count;
    for (auto &iter : hash) {
      if (count.count(iter.second)) {
        return false;
      }
      count[iter.second]++;
    }
    return true;
  }
};
// @lc code=end
