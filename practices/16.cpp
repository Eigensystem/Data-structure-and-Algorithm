#include <iostream>

using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    double a = 1.0;
    if (x == 1 || n == 0) return 1.0;
    else if (n < 0)
    {
      long long N = 0l - n;
      long long bit = 1;
      double tmp = x;
      for (int i = 0; i < 33; ++i)
      {
        if (bit & N) a *= tmp; 
        tmp *= tmp;
        bit *= 2;
      }
      return 1 / a;
    }
    else
    {
      long long N = n;
      long long bit = 1;
      double tmp = x;
      for (int i = 0; i < 33; ++i)
      {
        if (bit & N) a *= tmp;
        tmp *= tmp;
        bit *= 2;
      }
      return a;
    }
  }
};

int main() {
  Solution a;
  a.myPow(2.0, 10);
  return 0;
}