// https://leetcode.cn/problems/zheng-ze-biao-da-shi-pi-pei-lcof

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    if (p.size() == 0 && s.size() ==0) return true;
    if (p.size() == 0 && s.size() != 0) return false;
    vector<vector<bool>> flags(p.size() + 1, vector<bool>(s.size() + 1, 0));
    // initialize the first row and first col
    flags[0][0] = 1;
    flags[1][0] = 0;
    for (int i = 1; i <= s.size(); ++i) flags[0][i] = 0;
    for (int i = 2; i <= p.size(); ++i) {
      if (flags[i - 2][0] && p[i - 1] == '*')
        flags[i][0] = 1;
      else
        flags[i][0] = 0;
    }
    // dp
    for (int i = 1; i <= p.size(); ++i) {
      for (int j = 1; j <= s.size(); ++j) {
        if (p[i - 1] == '.') {
          flags[i][j] = flags[i - 1][j - 1];
        } else if (p[i - 1] == '*') {
          if (flags[i - 2][j] ||
              (flags[i][j - 1] && 
              (p[i - 2] == s[j - 1] || p[i - 2] == '.')))
            flags[i][j] = 1;
          else
            flags[i][j] = 0;
        } else {
          if (p[i - 1] == s[j - 1]) {
            flags[i][j] = flags[i - 1][j - 1];
          }
        }
      }
    }
    return flags[p.size()][s.size()];
  }
};