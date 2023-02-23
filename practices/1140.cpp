// https://leetcode.cn/problems/stone-game-ii/

#include <vector>

using namespace std;

class Solution
{
  int start(int M)
  {
    int s = 0;
    while (M != 2)
    {
      s += M;
      if (M % 2) M = M / 2 + 1;
      else M = M / 2;
    }
    return s + 2;
  }

public:
  int stoneGameII(vector<int>& piles)
  {
    vector<int> sub(piles.size()+1, 0);
    for (int i = piles.size() - 1; i >=0 ; --i)
    {
      sub[i] = sub[i+1] + piles[i]; 
    }
    
    vector<vector<int>> dp(50, vector<int>(piles.size()));
    for (int m = 50; m >=2; --m)
    {
      if (start(m) >= piles.size()) continue;
      int left = start(m);
      for (int i = piles.size() - 1; i >= left; --i)
      {
        
      }
    }
  }
};