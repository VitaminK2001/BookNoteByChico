package 学习笔记.Java.泛型.泛型类泛型接口.自定义泛型类;



class Order<T> {
    String orderName;
    int orderId;
    // 类的内部结构就可以使用类的泛型
    T orderT; //在实例化的时候指定T的类型
    public Order() {};
    public Order(String orderName, int orderId, T orderT) {
        this.orderName = orderName;
        this.orderId = orderId;
        this.orderT = orderT;
    }
    public T getOrderT() {
        return orderT;
    }
    public void setOrderT(T orderT) {
        this.orderT = orderT;
    }
    @Override
    public String toString() {
        return orderName + "---" + orderId + "---" + orderT;
    }
}

class Main {
    public static void main(String[] args) {
        // 类实例化的时候指明泛型类型
        Order<String> order1 = new Order<>("orderA", 1001, "order:AA");
        // 可以不指明
        Order order2 = new Order<>();
        order1.setOrderT("null");
    }
}

class SubOrder1<T> extends Order<T> { // 子类继承父类的时候不指明泛型类型
    // 此时SubOrder1仍然是泛型类
}

class SubOrder extends Order<String> { // 子类继承父类的时候指明泛型类型
    public static void main(String[] args) {
        // 因为子类继承的时候指明了父类泛型的类型所以实例化的时候不需要指明类型
        SubOrder sub1 = new SubOrder();
        SubOrder1<String> sub2 = new SubOrder1();
        sub2.setOrderT("order2...");
    }
}
