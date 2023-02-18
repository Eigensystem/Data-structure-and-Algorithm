#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    vector<int> arr;
public:
    vector<int> reversePrint(ListNode* head) {
        if (head == nullptr) 
        {
            return arr;
        }
        if (head -> next != nullptr)
        {
            reversePrint(head -> next);
        }
        arr.push_back(head -> val);
        return arr;
    }
};