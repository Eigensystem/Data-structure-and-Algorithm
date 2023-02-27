//https://leetcode.cn/problems/decrease-elements-to-make-array-zigzag
#include <vector>

using namespace std;

class Solution {
 public:
  int movesToMakeZigzag(vector<int>& num) {
    int sum_even = 0, sum_odd = 0;
    if (num.size() == 1) return 0;
    for (int i = 0; i < num.size(); ++i) {
      int tmp;
      if (i == 0)
        tmp = max(0, num[i] - num[i+1] + 1);
      else if(i == num.size() - 1) {
        tmp = max(0, num[i] - num[i-1] + 1);
      } 
      else {
        tmp = max(0, max(num[i] - num[i+1] + 1, num[i] - num[i-1] + 1));
      }
      if (i % 2 == 0) sum_even += tmp;
      else sum_odd += tmp;
    }
    return sum_odd > sum_even ? sum_even : sum_odd;
  }
};