/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int candy(vector<int> &ratings) {
    vector<int> count(ratings.size(), 0);
    count[0] = 1;
    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] > ratings[i - 1]) {
        count[i] = count[i - 1] + 1;
      } else {
        count[i] = 1;
      }
    }
    int ans = count.back();
    for (int i = ratings.size() - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) {
        count[i] = max(count[i], count[i + 1] + 1);
      }
      ans += count[i];
    }
    return ans;
  }
};
// @lc code=end
