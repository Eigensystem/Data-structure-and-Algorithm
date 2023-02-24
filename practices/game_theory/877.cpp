// https://leetcode.cn/problems/stone-game/

#include <vector>

using namespace std;

class Solution {
 public:
  bool stoneGame(vector<int>& piles) {
    vector<vector<int>> left(piles.size(), vector<int>(piles.size()));
    vector<vector<int>> right(piles.size(), vector<int>(piles.size()));

    int sum = 0;
    for (int i = 0; i < piles.size(); ++i) {
      sum += piles[i];
      // right sum from idx i to 0(included)
      left[i][i] = sum;
      // right sum from idx 0 to i(included)
      right[0][i] = sum;
    }
    for (int i = 1; i < piles.size(); ++i) {
      for (int j = 0; j < piles.size() - i; ++j) {
        left[i + j][j] = right[i][j] = right[0][i + j] - right[0][i - 1];
      }
    }

    vector<vector<int>> l_dp(piles.size(), vector<int>(piles.size()));
    vector<vector<int>> r_dp(piles.size(), vector<int>(piles.size()));
    for (int i = 0; i < piles.size(); ++i) {
      l_dp[piles.size() - 1][i] = left[i][0];
      r_dp[piles.size() - 1][i] = right[i][0];
    }
    for (int m = 1; m < piles.size(); ++m) {
      for (int j = 0; j < piles.size(); ++j) {
        if (j <= piles.size() - 1 - m) {
          l_dp[piles.size() - 1 - m][j] =
              right[j][m] -
              max(l_dp[piles.size() - m][j + 1], r_dp[piles.size() - m][j + m]);
        }
        if (j >= m) {
          r_dp[piles.size() - 1 - m][j] =
              left[j][m] -
              max(l_dp[piles.size() - m][j - m], r_dp[piles.size() - m][j - 1]);
        }
      }
    }
    return max(l_dp[0][0], r_dp[0][piles.size() - 1]) > sum / 2.0f;
  }
};