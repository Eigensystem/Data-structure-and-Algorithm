// https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumDeletions(string s) {
    vector<int> sub(s.size() + 1, 0);
    vector<int> dp(s.size(), 0);

    for (int i = s.size() - 1; i >= 0; --i) {
      sub[i] = s[i] == 'a' ? sub[i+1] + 1 : sub[i+1];
    }
    for (int i = s.size() - 2; i >= 0; --i) {
      if (s[i] == 'a') dp[i] = dp[i+1];
      else if (s[i] == 'b' && s[i+1] == 'b') {
        if (sub[i] > dp[i+1]) dp[i] = dp[i+1] + 1;
        else dp[i] = dp[i+1];
      }
      else dp[i] = dp[i+1] + 1;
    }
    return dp[0];
  }
};