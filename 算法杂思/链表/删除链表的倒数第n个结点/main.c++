#include <iostream>
using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyhead = new ListNode(0); // dummyhead
        dummyhead->next = head;
        ListNode *p = dummyhead;
        ListNode *q = dummyhead;
        int cnt = n; // 因为倒数第n个结点是算最后一个节点的
        while(cnt > 0){ // 题目中给出链表的长度是大于等于n的
            p = p->next;
            cnt--;
        }
        while(p != nullptr) {
            // 先判断p是否为最后一个节点
            if(p->next == nullptr) {
                // 如果是 则直接干掉q后面的一个节点
                q->next = q->next->next;
                return dummyhead->next;
            }else {
                // 如果不是则移动p和q
                p = p->next;
                q = q->next;
            }
        }
        return nullptr;
    }
};
int main(){
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = nullptr;
    s.removeNthFromEnd(head, 1);
}