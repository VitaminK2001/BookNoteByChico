package 学习笔记.Java.Scratch.test;

public class Test1 {
    public static void main(String[] args) {
        Manager m = new Manager();
        System.out.println(m.getSalary());
        char[] a = new char[10];
        a[0] = 'a';
        a[1] = 'b';
        a[2] = 'c';
        System.out.println(a);
    }
}
class Employee {
    private int baseSalary;
    public int getSalary() {
        return baseSalary;
    }
    public Employee() {
        baseSalary = 10;
    }
}
class Manager extends Employee {
    private int salary;
    @Override
    public int getSalary() {
        return salary + super.getSalary();
    }
    public Manager() {
        super();
        salary = 12;
    }
}


