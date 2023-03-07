// https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof

#include <vector>

using namespace std;

class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& poped) {
    int pop_end = -1, pop_pos = 0;
    vector<bool> flags(poped.size(), 0);
    for (int i = 0; i < poped.size(); ++i) {
      for (int j = 0; j < pushed.size(); ++j) {
        if (poped[i] == pushed[j]) {
          if (j > pop_end) {
            if (j > pop_end + 1) pop_pos = j;
            pop_end = j;
            flags[j] = 1;
          }
          else if (flags[j+1] && pop_pos == j+1) {
            flags[j] = 1;
            while (pop_pos != 0 && flags[pop_pos-1]) --pop_pos;
          }
          else return false;
          break;
        }
      }
    }
    return true;
  }
};