package 学习笔记.Java.面向对象;

class Variable {
    private static int a;
    private int b;
    /**
     * 局部变量
     * @param c
     */
    public void test(int c){
        int d;
    }
    // 只有共享变量  a b 会遇到并发问题
    // a类变量 保存在方法区中  b 成员变量 和对象保存在堆内存中 
    // c d 方法的局部变量保存在栈内存中
}
