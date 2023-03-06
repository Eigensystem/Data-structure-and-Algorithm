// https://leetcode.cn/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/?favorite=xb9nqhhg

#include <string>

using namespace std;

class Solution {
  bool isnum(char a) { return a >= '0' && a <= '9'; }

  bool notnum(char a) { return a < '0' || a > '9'; }

 public:
  bool isNumber(string s) {
    bool point = 0;
    int i = 0;
    // ' ' before number
    for (i; i < s.size() && s[i] == ' '; ++i) {
    }
    if (i == s.size()) return 0;

    if (s[i] != '+' && s[i] != '-' && s[i] != '.' && notnum(s[i])) return 0;
    if (s[i] == '.') {
      if ((i == s.size() - 1) || notnum(s[i+1])) return 0;
      else point = 1;
    } 
    if ((s[i] == '+' || s[i] == '-')) {
      if (i == s.size() - 1 || (s[i + 1] != '.' && notnum(s[i + 1])))
        return 0;
      if (s[i+1] == '.') {
        if (i+2 == s.size() || (s[i+2] != '+' && s[i+2] != '-' && notnum(s[i+2])))
          return 0;
        point = 1;
        ++i;
      }
    }
    ++i;
    for (i; i < s.size() && isnum(s[i]); ++i) {
    }
    if (i == s.size()) return 1;
    if (s[i] == '.') {
      if (point) return 0;
      if (i == s.size() - 1)
        return 1;
      else {
        ++i;
        for (i; i < s.size() && isnum(s[i]); ++i) {}
      }
    }
    if (s[i] == 'e' || s[i] == 'E') {
      if (i == s.size() - 1) return 0;
      else {
        ++i;
        if ((s[i] == '+' || s[i] == '-') && i != s.size() - 1)
          ++i;
        if (notnum(s[i])) return false;
        for (i; i < s.size() && isnum(s[i]); ++i) {}
      }
    }
    if (i == s.size()) return true;
    // ' ' after number
    for (i; i < s.size() && s[i] == ' '; ++i) {}
    if (i == s.size()) return true;
    else return false;
  }
};