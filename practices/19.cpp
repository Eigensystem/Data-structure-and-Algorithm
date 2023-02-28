// https://leetcode.cn/problems/zheng-ze-biao-da-shi-pi-pei-lcof

#include <string>

using namespace std;

class Solution {
  bool matchstar(int &idx, int &pos, string &p, string &s) {
    if (p[idx-1] == '.' && idx != p.size() - 1) {
      int j = s.size() - 1;
      for (int i = p.size() - 1; i > idx; --i) {
        if (p[i] != s[j]) return false;
        else --j;
      }
      if (j >= pos - 1) {
        pos = s.size();
        idx = p.size() - 1;
        return true;
      }
      else return false;
    }
    else if (p[idx-1] == '.' && idx == p.size() - 1) {
      pos = s.size();
      return true;
    }
    else if (p[idx-1] == p[idx+1]) {
      --pos;
      int cnt_p = 0, cnt_s = 0;
      for (int i = idx+1; p[i] == p[idx-1]; ++i) ++cnt_p;
      for (int i = pos; s[i] == s[pos]; ++i) ++cnt_s;
      if (cnt_p > cnt_s) return false;
      else {
        idx += cnt_p;
        pos += cnt_s;
        return true;
      }
    }
    else {
      while (pos < s.size() && s[pos] == p[idx-1]) {
        ++pos;
      }
      return true;
    }
  }

 public:
  bool isMatch(string s, string p) {
    bool flag = 1;
    int pos = 0;
    for (int i = 0; i < p.size(); ++i) {
      if (pos >= s.size()) {
        flag = 0;
        break;
      }
      if (p[i] == '.') {
        ++pos;
      }
      else if (p[i] == '*') {
        flag = matchstar(i, pos, p, s);
        if (!flag) return false;
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