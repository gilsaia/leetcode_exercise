/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool dfs(vector<string> &res, vector<vector<int>> &edge,
           unordered_map<string, int> &hash, vector<vector<string>> &tickets,
           vector<int> &used, string src) {
    if (res.size() == tickets.size() + 1) {
      return true;
    }
    int srcind = hash[src];
    vector<pair<string, int>> dstcan;
    for (int i = 0; i < edge[srcind].size(); ++i) {
      int edgeind = edge[srcind][i];
      if (used[edgeind]) {
        continue;
      }
      dstcan.push_back({tickets[edgeind][1], edgeind});
    }
    sort(dstcan.begin(), dstcan.end());
    for (int i = 0; i < dstcan.size(); ++i) {
      int edgeind = dstcan[i].second;
      res.push_back(dstcan[i].first);
      used[edgeind] = 1;
      bool can = dfs(res, edge, hash, tickets, used, dstcan[i].first);
      if (can) {
        return true;
      }
      used[edgeind] = 0;
      res.pop_back();
    }
    return false;
  }
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    vector<string> res;
    vector<vector<int>> edge;
    unordered_map<string, int> hash;
    vector<int> used(tickets.size(), 0);
    int ind = 0;
    for (int i = 0; i < tickets.size(); ++i) {
      if (!hash.count(tickets[i][0])) {
        hash[tickets[i][0]] = ind;
        edge.push_back(vector<int>());
        ind++;
      }
      if (!hash.count(tickets[i][1])) {
        hash[tickets[i][1]] = ind;
        edge.push_back(vector<int>());
        ind++;
      }
      edge[hash[tickets[i][0]]].push_back(i);
    }
    res.push_back("JFK");
    bool can = dfs(res, edge, hash, tickets, used, "JFK");
    return res;
  }
};
// @lc code=end
