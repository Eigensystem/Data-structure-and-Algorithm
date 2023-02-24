// https://leetcode.cn/problems/predict-the-winner/
#include <vector>

using namespace std;

class Solution {
 public:
  bool PredictTheWinner(vector<int>& nums) {
    vector<vector<int>> left(nums.size(), vector<int>(nums.size()));
    vector<vector<int>> right(nums.size(), vector<int>(nums.size()));

    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      // right sum from idx i to 0(included)
      left[i][i] = sum;
      // right sum from idx 0 to i(included)
      right[0][i] = sum;
    }
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < nums.size() - i; ++j) {
        left[i + j][j] = right[i][j] = right[0][i + j] - right[0][i - 1];
      }
    }

    vector<vector<int>> l_dp(nums.size(), vector<int>(nums.size()));
    vector<vector<int>> r_dp(nums.size(), vector<int>(nums.size()));
    for (int i = 0; i < nums.size(); ++i) {
      l_dp[nums.size() - 1][i] = left[i][0];
      r_dp[nums.size() - 1][i] = right[i][0];
    }
    for (int m = 1; m < nums.size(); ++m) {
      for (int j = 0; j < nums.size(); ++j) {
        if (j <= nums.size() - 1 - m) {
          l_dp[nums.size() - 1 - m][j] =
              right[j][m] -
              max(l_dp[nums.size() - m][j + 1], r_dp[nums.size() - m][j + m]);
        }
        if (j >= m) {
          r_dp[nums.size() - 1 - m][j] =
              left[j][m] -
              max(l_dp[nums.size() - m][j - m], r_dp[nums.size() - m][j - 1]);
        }
      }
    }
    return max(l_dp[0][0], r_dp[0][nums.size() - 1]) >= sum / 2.0f;
  }
};