#include <string>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
  void seri_trav(TreeNode* root, string &s) {
    s += "{";
    if (root != nullptr) {
      s += to_string(root->val);
      seri_trav(root->left, s);
      seri_trav(root->right, s);
    }
    s += "}";
  }

  void deseri_trav(string &s, TreeNode* root, int &start) {
    // left
    if (s[start+1] == '}') start += 2;
    else {
      TreeNode* left_root = new TreeNode(stoi(s.substr(start+1)));
      root->left = left_root;
      start += 1 + to_string(stoi(s.substr(start+1))).size();
      deseri_trav(s, left_root, start);
    }
    // right
    if (s[start+1] == '}') start += 2;
    else {
      TreeNode* right_root = new TreeNode(stoi(s.substr(start+1)));
      root->right = right_root;
      start += 1 + to_string(stoi(s.substr(start+1))).size();
      deseri_trav(s, right_root, start);
    }
    start += 1;
  }

  public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      string data;
      seri_trav(root, data);
      return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      if (data == "{}") return nullptr;
      TreeNode* root = new TreeNode(stoi(data.substr(1)));
      int start = 1 + to_string(stoi(data.substr(1))).size();
      deseri_trav(data, root, start);
      return root;
    }
};
