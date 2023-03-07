// https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/?favorite=xb9nqhhg


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  bool searchRoot(TreeNode* search, TreeNode* B) {
    if (search == nullptr) return false;
    if (search->val == B->val && match(search, B)) { 
      return true;
    }
    if (searchRoot(search->left, B) || searchRoot(search->right, B)) {
      return true;
    }
    else return false;
  }

  bool match(TreeNode* a, TreeNode* b) {
    if (a == nullptr || b->val != a->val) return false;
    if (b->left != nullptr) {
      if (!match(a->left, b->left))
        return false;
    }
    if (b->right != nullptr) { 
      if (!match(a->right, b->right))
        return false;
    }
    return true;
  }

 public:
  bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (B == nullptr) return false;
    return searchRoot(A, B);
  }
};