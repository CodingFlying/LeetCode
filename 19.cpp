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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prehead = new ListNode(-1);
        prehead->next = head;
        ListNode* p = prehead;
        ListNode* q = prehead;

        for (int i = 0; i < n + 1; i++) {
            q = q->next;
        }
        while (q) {
            p = p->next;
            q = q->next;
        }

        ListNode* delNode = p->next;
        p->next = delNode->next;
        delete delNode;

        ListNode* retNode = prehead->next;
        delete prehead;
        return retNode;
    }
};

int main() {
    
    vector<int> vals = {1, 3, 4, 6, 7};
    auto l1 = generateListNode(vals);
    Solution s1;

    auto l2 = s1.removeNthFromEnd(l1, 3);
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

