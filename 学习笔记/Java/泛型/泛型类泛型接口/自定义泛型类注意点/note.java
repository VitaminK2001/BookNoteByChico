package 学习笔记.Java.泛型.泛型类泛型接口.自定义泛型类注意点;

class Note <T>{
    // 静态方法中不能使用类的泛型
    // 泛型的指定是在实例化的时候，静态结构早于对象的创建

    // Cannot make a static reference to the non-static type T
    // public static void show(T o) {
    //     System.out.println(o);
    // }

    // 异常类不能是泛型的
    // No exception of type T can be thrown; an exception type must be a subclass of ThrowableJava(16777536)
    // public void show() {
    //     try {
            
    //     } catch (T t) {
    //         // TODO: handle exception
    //     }        
    // }

    // 泛型数组的创建
    // 编译错误
    // T[] arr = new T[10];
    // 编译通过
    // T[] arr = (T[]) new Object[10];
    
}

