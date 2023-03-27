#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    bool pushval(vector<int> &res, int push_lvl, int cur_lvl, TreeNode *root) {
      if (root == nullptr) return 1;
      if (cur_lvl == push_lvl) {
        res.push_back(root->val);
        return 0;
      }
      ++cur_lvl;
      bool left = pushval(res, push_lvl, cur_lvl, root->left);
      bool right = pushval(res, push_lvl, cur_lvl, root->right);
      return (left && right) ? 1 : 0;
    }

  public:
    vector<int> levelOrder(TreeNode *root) {
      vector<int> res;
      if (root == nullptr) return res;
      res.push_back(root->val);
      int i = 1;
      bool left = 0, right = 0;
      while (!left || !right) {
        left = pushval(res, i, 1, root->left);
        right = pushval(res, i, 1, root->right);
        ++i;
      } 
      return res;
    }
};