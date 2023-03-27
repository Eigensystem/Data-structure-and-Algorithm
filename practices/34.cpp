#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void sum(TreeNode* root, vector<int> path, int cur, int target, vector<vector<int>>& res) {
      cur += root->val;
      path.push_back(root->val);
      if (cur == target && root->left == nullptr && root->right == nullptr) {
        res.push_back(path);
        return;
      }
      if (root->left != nullptr) sum(root->left, path, cur, target, res);
      if (root->right != nullptr) sum(root->right, path, cur, target, res);
    }
  
  public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
      vector<vector<int>> res;
      if (root == nullptr) return res;
      vector<int> path;
      sum(root, path, 0, target, res);
      return res;
    }
};