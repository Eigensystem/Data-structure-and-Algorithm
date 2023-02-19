//time: 4ms

class Solution {
public:
  int fib(int n) {
    long a = 1, b = 1, c = 1;
    for (int i = 2; i < n; ++i)
    {
      c = (a + b) % 1000000007;
      a = b;
      b = c;
    }
    return c;
  }
};

//time: 0ms
class Solution_2 {
public:
  int fib(int n) {
    int a = 1, b = 1, c = 1;
    for (int i = 2; i < n; ++i)
    {
      c = (a + b) % 1000000007;
      a = b;
      b = c;
    }
    return c;
  }
};