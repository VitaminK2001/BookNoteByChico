package 算法.Leetcode.linklist;

class ListNode{
    int val;
    ListNode next;
    public ListNode(int val){
        this.val = val;
    }
    public ListNode(){
    }
}

class Solution {
    public ListNode sortList(ListNode head) {
        return sort(head, null);
    }
    public ListNode sort(ListNode head, ListNode tail){
        if(head == null) return null;
        if(head.next == tail){
            head.next = null;
            return head;
        }
        ListNode slow = head, fast = head;
        while(fast != tail) {
            fast = fast.next;
            slow = slow.next;
            if(fast != tail) fast = fast.next;
        }
        ListNode mid = slow;
        ListNode list1 = sort(head, mid);
        ListNode list2 = sort(mid, tail);
        return merge(list1, list2);
    }
    public ListNode merge(ListNode head1, ListNode head2){
        ListNode dummyHead = new ListNode(0);
        ListNode temp = dummyHead, temp1 = head1, temp2 = head2;
        while(temp1 != null && temp2 != null){
            if(temp1.val <= temp2.val){
                temp.next = temp1;
                temp1 = temp1.next;
            }
            else {
                temp.next = temp2;
                temp2 = temp2.next;
            }
            temp = temp.next;
        }
        if(temp1 != null){
            temp.next = temp1;
        }
        if(temp2 != null){
            temp.next = temp2;
        }
        return dummyHead.next;
    }
}















