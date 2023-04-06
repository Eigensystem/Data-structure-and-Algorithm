#include <iostream>
using namespace std;

class Solution {
public:
  int countDigitOne(int n) {
    int a[] = {0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000};
    int cnt = 0;
    long b = 10;
    long left = n / b;
    while (left) {
      ++cnt;
      b *= 10;
      left = n / b;
    }
    int total = 0;
    b = 10;
    for (int i = 0; i <= cnt; ++i) {
      int num = (n % b) / (b / 10);
      total += num * a[i];
      if (num > 1) total += b / 10;
      else if (num == 1) total += n % (b / 10) + 1;
      b *= 10;
    }
    return total;
  }
};
