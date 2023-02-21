// https://leetcode.cn/problems/number-of-ways-of-cutting-a-pizza/

#include <vector>
#include <string>

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
        sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
        sum[i][j] = pizza[i][j] == 'A' ? sum[i][j] + 1 : sum[i][j]; 
      }
    }

    vector<vector<vector<int>>> dp(k-1, vector<vector<int>>(rows, vector<int>(cols, 0)));
    
  }
};