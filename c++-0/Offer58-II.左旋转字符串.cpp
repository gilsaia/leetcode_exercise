#include <string>
using namespace std;
class Solution {
public:
  string reverseLeftWords(string s, int n) {
    string tmp = s.substr(0, n);
    for (int i = n; i < s.size(); ++i) {
      s[i - n] = s[i];
    }
    s.erase(s.end() - n, s.end());
    return s + tmp;
  }
};