// https://leetcode.cn/problems/stone-game-ii/

#include <vector>

using namespace std;

class Solution {
  int start(int M) {
    int s = 0;
    if (M == 1) return 0;
    while (M != 2) {
      s += M;
      if (M % 2)
        M = M / 2 + 1;
      else
        M = M / 2;
    }
    return s + 2;
  }

 public:
  int stoneGameII(vector<int>& piles) {
    vector<int> sub(piles.size() + 1, 0);
    for (int i = piles.size() - 1; i >= 0; --i) {
      sub[i] = sub[i + 1] + piles[i];
    }

    vector<vector<int>> dp(50, vector<int>(piles.size() + 1));
    for (int m = 50; m >= 1; --m) {
      if (start(m) >= piles.size()) continue;
      int left = start(m);
      for (int i = piles.size() - 1; i >= left; --i) {
        int max = 0;
        for (int j = i + 1; j <= i + m && j <= piles.size(); ++j) {
          int tmp = sub[i] - dp[m][j];
          if (tmp > max) max = tmp;
        }
        for (int j = i + m + 1; j <= i + 2 * m && j <= piles.size(); ++j) {
          int tmp = sub[i] - dp[j - i][j];
          if (tmp > max) max = tmp;
        }
        dp[m][i] = max;
      }
    }
    return dp[1][0];
  }
};