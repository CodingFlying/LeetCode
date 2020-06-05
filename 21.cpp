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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        else if (l2 == nullptr) return l1;
        else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};

int main() {
    
    vector<int> v1 = {1, 3, 4, 6, 7};
    vector<int> v2 = {1, 3, 3, 4, 10};
    auto l1 = generateListNode(v1);
    auto l2 = generateListNode(v2);

    Solution s1;

    auto l3 = s1.mergeTwoLists(l1, l2);
    printListNode(l1);
    printListNode(l2);
    printListNode(l3);

    freeListNode(l1);
    freeListNode(l2);
    freeListNode(l3);
    
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