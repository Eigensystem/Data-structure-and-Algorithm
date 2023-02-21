// https://leetcode.cn/problems/minimum-number-of-taps-to-open-to-water-a-garden/

#include <vector>

using namespace std;

class Solution
{
public:
  int minTaps(int n, vector<int>& ranges)
  {
    vector<int> ends(n+1, 0);
    for (int i = 0; i < ranges.size(); ++i)
    {
      int start = i - ranges[i];
      int end = i + ranges[i];
      if (start < 0) start = 0;
      if (end > n) end = n;
      if (ends[start] < end) ends[start] = end;
    }
    int last = 0, next = ends[0];
    int max = next;
    int cnt = 1;
    while (max != n)
    {
      for (int i = last + 1; i <= next; ++i)
      {
        if (ends[i] > max) max = ends[i];
      }
      if (max == next) return -1; 
      last = next;
      next = max;
      ++cnt;
    }
    return cnt;
  }
};