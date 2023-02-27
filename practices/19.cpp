// https://leetcode.cn/problems/zheng-ze-biao-da-shi-pi-pei-lcof

#include <string>

using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    bool flag = 1;
    int pos = 0, i = 0;
    for (i; i < p.size(); ++i) {
      if (pos >= s.size()) {
        flag = 0;
        break;
      }
      if (p[i] == '.') {
        ++pos;
      }
      else if (p[i] == '*') {
        int cnt = 0;
        while ((p[i-1] == s[pos] || p[i-1] == '.') && pos < s.size()) {
          if (p[i+cnt+1] == p[i-1]) ++cnt;
          ++pos;
        }
      }
      else {
        if (p[i] == s[pos]) ++pos;
        else if (i != p.size() - 1 && p[i+1] == '*') {
          ++i;
          continue;
        }
        else {
          flag = 0;
          break;
        }
      }
    }
    return flag && pos == s.size();
  }
};