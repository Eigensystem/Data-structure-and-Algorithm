// https://leetcode.cn/problems/number-of-ways-of-cutting-a-pizza/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
  int ways(vector<string>& pizza, int k)
  {
    int rows = pizza.size(), cols = pizza[0].size();
    vector<vector<int>> sum(rows+1, vector<int>(cols+1, 0));
    for (int i = rows - 1; i >= 0; --i)
    {
      for (int j = cols - 1; j >= 0; --j)
      {
        sum[i][j] = sum[i][j+1] + sum[i+1][j] - sum[i+1][j+1];
        sum[i][j] = (pizza[i][j] == 'A' ? sum[i][j] + 1 : sum[i][j]); 
      }
    }
    vector<vector<vector<int>>> dp(k, vector<vector<int>>(rows, vector<int>(cols, 0)));
    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        if (sum[i][j]) dp[0][i][j] = 1;
      }
    }
    for (int n = 1; n < k; ++n)
    {
      for (int i = rows - 1; i >= 0; --i)
      {
        for (int j = cols - 1; j >= 0; --j)
        {
          long long cnt = 0;
          for (int x = i + 1; x < rows; ++x)
          {
            if (sum[i][j] - sum[x][j]) cnt += dp[n-1][x][j] % 1000000007;
          }
          for (int y = j + 1; y < cols; ++y)
          {
            if (sum[i][j] - sum[i][y]) cnt += dp[n-1][i][y] % 1000000007;
          }
          dp[n][i][j] = cnt % 1000000007;
        }
      }
    }
    return dp[k-1][0][0];
  }
};

int main() {
  vector<string> pizza = {"A..","AA.","..."};
  Solution a;
  int c = a.ways(pizza, 3);
  cout << c;
}