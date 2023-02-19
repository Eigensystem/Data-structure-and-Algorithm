#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>&inorder)
  {
    if (preorder.size() == 0) 
    {
      return nullptr;
    }
    TreeNode* root = new TreeNode(preorder.front());
    build(preorder, inorder, root);
    return root;
  }
  
  void build(vector<int>& preorder, vector<int>& inorder, TreeNode* root)
  {
    int cnt = 0;
    for (auto &i : inorder) 
    {
      if (root->val == i)
      {
        break;
      }
      ++cnt;
    }
    if (cnt != 0)
    {
      vector<int> left_preorder(preorder.begin()+1, preorder.begin()+cnt+1);
      vector<int> left_inorder(inorder.begin(), inorder.begin()+cnt);
      TreeNode* left_root = new TreeNode(left_preorder.front());
      root->left = left_root;
      build(left_preorder, left_inorder, left_root);
    }
    if(cnt != inorder.size() - 1)
    {
      vector<int> right_preorder(preorder.begin()+cnt+1, preorder.end());
      vector<int> right_inorder(inorder.begin()+cnt+1, inorder.end());
      TreeNode* right_root = new TreeNode(right_preorder.front());
      root->right = right_root;
      build(right_preorder, right_inorder, right_root);
    }
    return;
  }
};
