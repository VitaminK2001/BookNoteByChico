package 学习笔记.Java.面向对象;

import java.util.HashSet;
import java.util.Objects;

public class equals和hashcode {
    public static void main(String[] args) {
        Person p1 = new Person("chico");
        Person p2 = new Person("chico");
        HashSet<Person> set = new HashSet<>();
        set.add(p1);
        set.add(p2);
        System.out.println(set.size());
    }
}
class Person {
    private String name;
    public Person(String name) {
        this.name = name;
    }
    @Override
    public boolean equals(Object o) {
        if(this == o) return true;
        if(o == null || this.getClass() != o.getClass()) return false;
        Person p = (Person) o;
        return name != null ? name.equals(p.name) : p.name == null;
    }
    @Override
    public int hashCode() {
        return Objects.hash(name);
    }
    // 两个对象相等的严格定义是对象内容相等(equals的值)和哈希值相等(hashCode)的结果
}

