#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void addAtEnd(ListNode* head, ListNode* node) {
    ListNode* p = head;
    if (p == NULL) {
        head = node;
        return;
    }
    while (p != NULL && p->next != NULL) {
        p = p->next;
    }

    p->next = node;
}

ListNode* oddEvenList(ListNode* head) {
    ListNode* p = head;
    ListNode* evenList = NULL;

    int ctr = 1;
    while (p != NULL && p->next != NULL) {
        ListNode* temp = p->next;

    }   
}

int main() {
    
    ListNode* node = new ListNode(2);

    int n;
    cin>>n;
    ListNode* head = NULL;
    while (n != -1) {
        ListNode* node = new ListNode(n);
        node->next = head;
        head = node;
        cin>>n;
    }

    ListNode* p = head;
    while (p != NULL) {
        cout<<p->val<<"->";
        p = p->next;
    }
    cout<<endl;


    return 0;
}
