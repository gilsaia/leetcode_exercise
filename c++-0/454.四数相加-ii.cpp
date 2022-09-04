/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                   vector<int> &nums4) {
    unordered_map<int, int> hash;
    for (int &i : nums1) {
      for (int &j : nums2) {
        hash[i + j]++;
      }
    }
    int ans = 0;
    for (int &i : nums3) {
      for (int &j : nums4) {
        ans += hash[-i - j];
      }
    }
    return ans;
  }
};
// @lc code=end
