/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    int left = 0, right = 0, temp_sum = 0, temp_cate = 0, ans = 0;
    map<int, int> check;
    while (right < fruits.size()) {
      while (right < fruits.size() && temp_cate <= 2) {
        if (!check[fruits[right]]) {
          if (temp_cate == 2) {
            break;
          }
          check[fruits[right]]++;
          ++temp_cate;
          ++temp_sum;
        } else {
          check[fruits[right]]++;
          ++temp_sum;
        }
        ++right;
      }
      ans = max(ans, temp_sum);
      while (left < fruits.size() && temp_cate >= 2) {
        --check[fruits[left]];
        --temp_sum;
        if (!check[fruits[left]]) {
          --temp_cate;
        }
        ++left;
      }
    }
    return ans;
  }
};
// @lc code=end
