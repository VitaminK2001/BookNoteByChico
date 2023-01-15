package 学习笔记.Java.面向对象;


class Rectangle {
    public int a;
    int b;
    private int getB(){
        return b;
    }
    public int getA(){
        return a;
    }
}

class Square extends Rectangle{
    int r;
    public static void main(String[] args) {
        Square s = new Square(); // 如果在方法中构造类的对象需要实例化 但是类中的属性不需要
        // The method getB() from the type Rectangle is not visible
        // 子类继承了父类的所有属性和方法，但是因为可见性的原因不能使用private的属性和方法
        // s.getB();
        
        // The field Rectangle.b is not visible
        // s.b = 10;

        // 可以使用所有public 和 protected 的方法
        // public : 任意处可见
        // protected : 子类可见
        s.a = 10;

        s.getA();
    }

}

class Main{
    public static void main(String[] args) {
        
    }
}
