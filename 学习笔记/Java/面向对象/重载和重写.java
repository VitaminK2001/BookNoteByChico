package 学习笔记.Java.面向对象;

class Dog {
    public void bark() {
        System.out.println("woof ");
    }
    // 重载方法 方法名相同 参数列表不同
    public void bark(int num) {
        for(int i = 0; i < num; ++i){
            System.out.println("woof ");
        }
    }
    // 被重载的方法必须改变 参数列表
    // 可以改变 返回类型、访问修饰符、新的或更广的检查异常
    // 方法能够在同一个类中或者在一个子类中被重载
}

class Hound extends Dog {
    public void sniff(){
        System.out.println("sniff ");
    }
    public void bark() {
        System.out.println("bowl ");
    }
}
class OverridingTest{
    public static void main(String[] args) {
        // dog变量指向的是Hound对象的引用
        Dog dog = new Hound();
        dog.bark();
        // 重写满足的要求
        // 必须相同: 参数列表 返回类型 
        // 访问级别限制性 只能相同或更弱
        // 不能抛出新异常 或 比被重写方法声明的异常有更广泛的检查异常
        // 可以抛出更少或不抛出异常 这只针对检查类异常有限制 对于非检查类异常无限制
        // 比如RuntimeException及其子类
        // 运行时异常抛出和没抛出编译器都不会检查
        // 不能抽血final
        // 如果不能继承一个方法 则不能重写这个方法
    }
}

// 重载是一个编译期概念 重写是一个运行期概念
// 重载遵循编译期绑定 编译时根据参数变量的类型判断应该调用那个方法
// 重写遵循运行期绑定 运行是更具引用变量所指向的实际对象的类型来调用方法