#include <math.h>

using namespace std;

class Solution
{
public:
  int cuttingRope(int n)
  {
    if (n == 2) return 1;
    if (n == 3) return 2;
    int base = n / 3;
    int mul;
    if (n % 3 == 0) mul = pow(3, base);
    if (n % 3 == 1) mul = pow(3, base - 1) * 4;
    if (n % 3 == 2) mul = pow(3, base) * 2;
    return mul;
  }
};