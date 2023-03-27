#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      int level = 0;
      stack<TreeNode *>a, b;
      vector<vector<int>> res;
      if (root == nullptr) return res;
      a.push(root);
      while (!a.empty() || !b.empty()) {
        vector<int> sub_res;
        if (level % 2 == 0) {
          while (!a.empty()) {
            TreeNode* node = a.top();
            a.pop();
            sub_res.push_back(node->val);
            if (node->left != nullptr) b.push(node->left);
            if (node->right != nullptr) b.push(node->right);
          }
        }
        else {
          while (!b.empty()) {
            TreeNode* node = b.top();
            b.pop();
            sub_res.push_back(node->val);
            if (node->right != nullptr) a.push(node->right);
            if (node->left != nullptr) a.push(node->left);
          }
        }
        res.push_back(sub_res);
        ++level;
      }
      return res;
    }
};