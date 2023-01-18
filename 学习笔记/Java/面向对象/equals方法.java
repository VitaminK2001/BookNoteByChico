package 学习笔记.Java.面向对象;

class Person {
    String name;
    @Override
    public boolean equals(Object o) {
        // 实现通过==判断对象是否是同一个
        // 在判断是否是同一类型
        // 最后比较值
        if(this == o) return true;
        if(o == null || o.getClass() != this.getClass()) return false;
        Person p = (Person) o;
        return name != null ? name.equals(p.name) : p.name == null;
    }
}
