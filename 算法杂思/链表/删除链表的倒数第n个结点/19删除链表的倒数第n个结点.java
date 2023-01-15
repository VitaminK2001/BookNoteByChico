package 算法杂思.链表.删除链表的倒数第n个结点;

import java.util.LinkedList;

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
    //方法1模拟
    public int getlength(ListNode head){
        int len = 0;
        while(head != null){
            len++;
            head = head.next;
        }
        return len;
    }
    //注意删除节点需要多设置一个头结点dummynode以防删除的是第一个节点
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int len = getlength(head);
        ListNode dummynode = new ListNode(0, head);
        ListNode cur = dummynode;
        // 从头结点移动到倒数第n个结点前一个节点一共需要移动len-n-1次
        // 所以从dummynode移动到倒数第n个结点一共需要移动Len-n次
        for(int i = 0; i < len - n; ++i){
            cur = cur.next;
        }
        cur.next = cur.next.next;
        ListNode ans = dummynode.next;
        return ans;
    }    
}
class Solution2{
    // 方法2 栈
    public ListNode removeNthFromEnd(ListNode head, int n) {
        LinkedList<ListNode> stack = new LinkedList<>();
        ListNode dummynode = new ListNode(0, head);
        ListNode cur = dummynode;
        while(cur != null){
            stack.push(cur);
            cur = cur.next;
        }
        int count = 0;
        ListNode prev = new ListNode();
        while(count < n-1) { //pop出n-1个结点
            stack.pop();
            count++;
        }
        //pop出第n个结点
        prev = stack.pop();
        cur = stack.pop();
        cur.next = prev.next;
        return dummynode.next;
    }
}
class Solution3{
    //方法3 双指针
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummynode = new ListNode();
        ListNode second = new ListNode();
        ListNode first = new ListNode();
        second = dummynode; first = dummynode;
        int cnt = n;
        while(cnt != 0){
            first = first.next;
            cnt--;
        }
        while(first.next != null){
            second = second.next;
            first = first.next;
        }
        second.next = second.next.next;
        return dummynode.next;
    }
}