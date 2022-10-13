/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */
#include <algorithm>
#include <list>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  static bool cmp(vector<int> &a, vector<int> &b) {
    if (a[0] == b[0]) {
      return a[1] > b[1];
    }
    return a[0] < b[0];
  }
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    int n = people.size();
    list<int> seats;
    for (int i = 0; i < n; ++i) {
      seats.push_back(i);
    }
    sort(people.begin(), people.end(), cmp);
    vector<vector<int>> res(n, vector<int>(2, 0));
    for (int i = 0; i < n; ++i) {
      int noseat = people[i][1];
      auto iter = seats.begin();
      for (int j = 0; j < noseat; ++j) {
        ++iter;
      }
      res[*iter][0] = people[i][0];
      res[*iter][1] = people[i][1];
      seats.erase(iter);
    }
    return res;
  }
};
// @lc code=end
