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


class Solution{
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        //定义一个新的链表头指针
        ListNode prev = new ListNode(0);
        //定义进位
        int carry = 0;
        //定义可以移动的指针
        ListNode cur = prev;
        while(l1 != null || l2 != null){
            int x = l1 == null ? 0 : l1.val;
            int y = l2 == null ? 0 : l2.val;
            int sum = x + y + carry;
            carry = sum / 10;
            sum = sum % 10;
            cur.next = new ListNode(sum);
            cur = cur.next;
            if(l1 != null){
                l1 = l1.next;
            }
            if(l2 != null){
                l2 = l2.next;
            }
        }
        if(carry == 1){
            cur.next = new ListNode(carry);
        }
        return prev.next;
    }
}
