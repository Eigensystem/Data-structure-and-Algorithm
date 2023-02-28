// https://leetcode.cn/problems/zheng-ze-biao-da-shi-pi-pei-lcof

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    vector<vector<bool>> flags(p.size() + 1, vector<bool>(s.size() + 1, 0));
    flags[0][0] = 1;
    for (int i = 1; i <= p.size(); ++i) {
      for (int j = 1; j <= s.size(); ++j) {
        if (p[i-1] == '.') {
          flags[i][j] = flags[i-1][j-1];
        }
        else if (p[i-1] == '*') {
          // flags[i][j] = 
        }
        else {
          if (p[i-1] == s[j-1]) {
            flags[i][j] = flags[i-1][j-1];
          }
        }
      }
    }
  }
};