#include <vector>

using namespace std;

class Solution {
  public:
    bool verifyPostorder(vector<int>& postorder) {
      if (postorder.empty()) return true;
      return test(postorder, 0, postorder.size());
    }

    bool test(vector<int>& postorder, int start, int end) {
      if (start + 1 >= end) return true;
      int root = postorder[end-1];
      int next_start = end - 1;
      bool flag = 0;
      for (int i = start; i < end - 1; ++i) {
        if (flag && postorder[i] < root) return false;
        if (!flag && postorder[i] > root) {
          next_start = i;
          flag = 1;
        }
      }
      return test(postorder, start, next_start) && test(postorder, next_start, end-1);
    }
};

