// https://leetcode.cn/problem-list/xb9nqhhg/
#include <math.h>

using namespace std;

class Solution
{
public:
  int cuttingRope(int n)
  {
    if (n == 2) return 1;
    if (n == 3) return 2;
    int max = n / 2;
    int mul = 0;
    for (int m = 2; m <= max; ++m)
    {
      int tmp = pow(n / m, m - n % m) * pow(n / m + 1, n % m);
      if (tmp > mul)
        mul = tmp;
    }
    return mul;
  }
};