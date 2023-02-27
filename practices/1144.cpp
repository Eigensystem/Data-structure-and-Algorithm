//https://leetcode.cn/problems/decrease-elements-to-make-array-zigzag
#include <vector>

using namespace std;

class Solution {
 public:
  int movesToMakeZigzag(vector<int>& num) {
    int sum_even = 0, sum_odd = 0;
    if (num.size() == 1) return 0;
    for (int i = 0; i < num.size(); i += 2) {
      if (i == 0) {
        if (num[i] >= num[i+1]) sum_even += num[i] - num[i+1] + 1;
        continue;
      } 
      else if(i == num.size() - 1) {
        if (num[i] >= num[i-1]) sum_even += num[i] - num[i-1] + 1;
        continue;
      } 
      else if(num[i] >= num[i+1] || num[i] >= num[i-1]) {
        if (num[i+1] < num[i-1]) sum_even += num[i] - num[i+1] + 1;
        else sum_even += num[i] - num[i-1] + 1;
      }
    }
    for (int i = 1; i < num.size(); i += 2) {
      if(i == num.size() - 1) {
        if (num[i] >= num[i-1]) sum_odd += num[i] - num[i-1] + 1;
        continue;
      } 
      else if(num[i] >= num[i+1] || num[i] >= num[i-1]) {
        if (num[i+1] < num[i-1]) sum_odd += num[i] - num[i+1] + 1;
        else sum_odd += num[i] - num[i-1] + 1;
      }
    }
    return sum_odd > sum_even ? sum_even : sum_odd;
  }
};