package 学习笔记.Java.容器;

import java.util.LinkedList;

public class Tlist {
    static LinkedList<Integer> list;
    public static void main(String[] args) {
        list = new LinkedList<>();
        
        //如果用push和pop就是将list当做stack用
        list.push(1);
        list.push(2);
        list.push(3);    
        System.out.println(list.pop());
        System.out.println(list.pop());
        System.out.println(list.pop());
        
        //如果用offer和poll就是当做queue用
        list.offer(1);
        list.offer(2);
        list.offer(3);
        System.out.println(list.poll());
        System.out.println(list.poll());
        System.out.println(list.poll());
    }
    

    
    
}
