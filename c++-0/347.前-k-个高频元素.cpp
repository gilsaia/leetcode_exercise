/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
struct cmp {
  bool operator()(pair<int, int> &lhs, pair<int, int> &rhs) {
    return lhs.second > rhs.second;
  }
};
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> hash;
    for (int &num : nums) {
      hash[num]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
    for (auto &it : hash) {
      que.push(it);
      if (que.size() > k) {
        que.pop();
      }
    }
    vector<int> ans;
    while (!que.empty()) {
      ans.push_back(que.top().first);
      que.pop();
    }
    return ans;
  }
};
// @lc code=end
