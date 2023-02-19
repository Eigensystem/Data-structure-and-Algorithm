#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
  unordered_map<int, int> u = {};

public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>&inorder)
  {
    if (preorder.size() == 0) 
    {
      return nullptr;
    }
    TreeNode* root = new TreeNode(preorder.front());
    for (int i = 0; i < inorder.size(); ++i)
    {
      u[inorder[i]] = i;
    }
    build(preorder, inorder, root, 0, preorder.size(), 0, inorder.size());
    return root;
  }
  
  void build(vector<int>& preorder, vector<int>& inorder, TreeNode* root, int pre_left, int pre_right, int in_left, int in_right)
  {
    int in_root_idx = u[preorder[pre_left]];
    if (in_root_idx != in_left)
    {
      TreeNode* left_root = new TreeNode(preorder[pre_left+1]);
      root->left = left_root;
      build(preorder, inorder, left_root, pre_left + 1, pre_left + 1 + in_root_idx - in_left, in_left, in_root_idx);
    }
    if(in_root_idx != in_right - 1)
    {
      TreeNode* right_root = new TreeNode(preorder[pre_left + 1 + in_root_idx - in_left]);
      root->right = right_root;
      build(preorder, inorder, right_root, pre_left + 1 + in_root_idx - in_left, pre_right, in_root_idx + 1, in_right);
    }
    return;
  }
};