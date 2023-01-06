package 算法.Leetcode.linklist;
class ListNode{
    int val;
    ListNode next;
    ListNode() {};
    ListNode(int val) {
        this.val = val;
    }
    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode head = new ListNode();
        ListNode res = head;
        ListNode cur1 = list1;
        ListNode cur2 = list2;
        while(cur1 != null && cur2 != null){
            if(cur1.val < cur2.val){
                head.val = cur1.val;
                cur1 = cur1.next;
            }else {
                head.val = cur2.val;
                cur2 = cur2.next;
            }
            head.next = new ListNode();
            head = head.next;
        }
        while(cur1 != null){
            head.val = cur1.val;
            head.next = new ListNode();
            head = head.next;
            cur1 = cur1.next;
        }
        while(cur2 != null){
            head.val = cur2.val;
            head.next = new ListNode();
            head = head.next;
            cur2 = cur2.next;
        }
        return res;
    }
}
class Solution2{
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null){
            return l2;
        }else if(l2 == null){
            return l1;
        }else {
            if(l1.val < l2.val){
                l1.next = mergeTwoLists(l1.next, l2);
                return l1;
            }else{
                l2.next = mergeTwoLists(l1, l2.next);
                return l2;
            }
        }
    }
}
