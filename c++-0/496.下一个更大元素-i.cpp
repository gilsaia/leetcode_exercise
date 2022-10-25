/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> hash;
    stack<int> sta;
    for (int i = 0; i < nums2.size(); ++i) {
      if (sta.empty()) {
        sta.push(i);
        continue;
      }
      while (!sta.empty() && nums2[i] > nums2[sta.top()]) {
        hash[nums2[sta.top()]] = nums2[i];
        sta.pop();
      }
      sta.push(i);
    }
    while (!sta.empty()) {
      hash[nums2[sta.top()]] = -1;
      sta.pop();
    }
    vector<int> ans(nums1.size(), 0);
    for (int i = 0; i < nums1.size(); ++i) {
      ans[i] = hash[nums1[i]];
    }
    return ans;
  }
};
// @lc code=end
