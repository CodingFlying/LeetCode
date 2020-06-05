#include <iostream>
#include <vector> 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* generateListNode(std::vector<int> vals);
void freeListNode(ListNode* head);
void printListNode(ListNode* head);

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* prehead = new ListNode(-1);
        prehead->next = head;
        ListNode* cur = prehead;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* start = cur->next;
            ListNode* end = cur->next->next;
            cur->next = end;
            start->next = end->next;
            end->next = start;
            cur = cur->next->next;
        }
        return prehead->next;
    }
};

int main() {
    
    vector<int> v1 = {1, 3, 4, 6, 7};
    auto l1 = generateListNode(v1);
    printListNode(l1);

    Solution s1;
    auto l2 = s1.swapPairs(l1);
    printListNode(l2);

    freeListNode(l1);
    freeListNode(l2);
    return 0;
}



ListNode* generateListNode(std::vector<int> vals)  {
    ListNode *res = nullptr;
    ListNode *last = nullptr;
    for(auto val : vals) {
        if(last) {
            last->next = new ListNode(val);
            last = last->next;
        }
        else {
            res = new ListNode(val);
            last = res;
        }
    }
    return res;
}

void freeListNode(ListNode* head) {
    ListNode* node = head;
    while(node) {
        auto temp = node->next;
        delete node;
        node = temp;
    }
}

void printListNode(ListNode* head) {
    ListNode* node = head;
    while(node) {
        cout << node->val << ", ";
        node = node->next;
    }
    cout << endl;
}