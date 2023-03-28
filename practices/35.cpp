#include <unordered_map>

using namespace std;

class Node {
  public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
      val = _val;
      next = nullptr;
      random = nullptr;
    }
};

class Solution {
  public:
    Node* copyRandomList(Node* head) {
      if (head == nullptr) return nullptr;
      unordered_map<Node *, Node *> addr_map;
      Node *new_head = new Node(head->val);
      addr_map[head] = new_head;
      Node *last = new_head, *old = head->next;
      while (old != nullptr) {
        Node *cur = new Node(old->val);
        addr_map[old] = cur;
        last->next = cur;
        last = cur;
        old = old->next;
      }
      old = head;
      Node *cur = new_head;
      while(cur != nullptr) {
        if (old->random == nullptr) cur->random = nullptr;
        else cur->random = addr_map[old->random];
        old = old->next;
        cur = cur->next;
      }
      return new_head;
    }
};