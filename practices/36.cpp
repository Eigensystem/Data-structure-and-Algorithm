// #include 

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};


class Solution {
  void tolist(Node *root, Node *last) {
    Node *tmp;
    while (root->right != nullptr) {
      last->left = root->right;
      root->right = last->left->left;
      last->left->left = root;
      tmp = last->left;
      tolist(last->left, last);
      last = tmp;
    }
  }
  
  void treeToList(Node *root, Node *last) {
    if (root->left != nullptr) treeToList(root->left, root);
    tolist(root, last);
  }

  void listToDoublylist(Node *cur, Node *last, Node *head) {
    if (cur->left != nullptr) listToDoublylist(cur->left, cur, head);
    else {
      cur->left = head->left;
      head->right = cur;
    }
    cur->right = last;
  }

  public:
    Node* treeToDoublyList(Node* root) {
      if (root == nullptr) return nullptr;
      Node *head = new Node(0, root, nullptr);
      treeToList(root, head);
      listToDoublylist(head->left, head, head);
      head->left->right = head->right;
      return head->right;
    }
};