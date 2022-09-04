/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> hash;
    for (int &i : nums1) {
      hash[i]++;
    }
    vector<int> ans;
    for (int &i : nums2) {
      if (hash[i] > 0) {
        ans.push_back(i);
        hash[i]--;
      }
    }
    return ans;
  }
};
// @lc code=end
