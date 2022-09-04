/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#include <set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    set<int> hash;
    for (int &i : nums1) {
      hash.insert(i);
    }
    vector<int> ans;
    for (int &i : nums2) {
      if (hash.count(i)) {
        hash.erase(i);
        ans.push_back(i);
      }
    }
    return ans;
  }
};
// @lc code=end
