/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int res = 0;
    int minprice = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] < minprice) {
        minprice = prices[i];
      }
      if (prices[i] >= minprice && prices[i] <= minprice + fee) {
        continue;
      }
      if (prices[i] > minprice + fee) {
        res += prices[i] - minprice - fee;
        minprice = prices[i] - fee;
      }
    }
    return res;
  }
};
// @lc code=end
