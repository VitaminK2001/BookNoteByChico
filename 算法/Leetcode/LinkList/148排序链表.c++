#include <iostream>
using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

class Solution{
public:
    ListNode* sortList(ListNode* head){
        return sortList(head, nullptr);
    }
    ListNode* sortList(ListNode* head, ListNode* tail){
        //保留head不保留tail
        if(head == nullptr){
            return head;
        }
        if(head->next == tail){
            head->next = nullptr;
            return head;
        }
        ListNode *fast = head, *slow = head;
        while(fast != tail){
            slow = slow->next;
            fast = fast->next;
            if(fast != tail){
                fast = fast->next;
            }
        }
        ListNode *mid = slow ;
        return merge(sortList(head, mid), sortList(mid, tail));
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = l1, *temp2 = l2;
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1->val <= temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
            }else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if(temp1 != nullptr){
            temp->next = temp1;
        }else if(temp2 != nullptr){
            temp->next = temp2;
        } //免得加入通过为空时多出的一个空指针
        return dummyHead->next;
    }
};