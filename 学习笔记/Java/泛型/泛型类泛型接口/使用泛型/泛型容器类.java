package 学习笔记.Java.泛型.泛型类泛型接口.使用泛型;


import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;


class Test {
    public static void main(String[] args) {
        // 以ArrayList为例
        ArrayList a = new ArrayList<>();
        a.add(1);
        a.add(2);
        // 类型不安全
        a.add("a");
        for(Object obj : a) {
            // 类型强转时可能出现ClassCastException
            int o = (Integer) obj;
            System.out.println(obj);
        }

        ArrayList<Integer> b = new ArrayList<>();
        b.add(1);
        b.add(2);
        Iterator<Integer> it = b.iterator();
        while(it.hasNext()) {
            int num = it.next();
            System.out.println(num);
        }
    }
}

class Test2 {
    public static void main(String[] args) {
        // 以map为例
        HashMap<String, Integer> map = new HashMap<>();
        map.put("tom", 1);
        map.put("jerry", 2);
        // 泛型的嵌套
        Set<Map.Entry<String, Integer> > set = map.entrySet();
        Iterator<Map.Entry<String, Integer> > iterator = set.iterator();
        while(iterator.hasNext()) {
            Map.Entry<String, Integer> e = iterator.next();
            String key = e.getKey();
            Integer value = e.getValue();
            System.out.println(key + "---" + value);
        }
    }
}


// class Employee implements Comparable{
//     int salary;
//     int id;
//     String name;
//     @Override
//     public int compareTo(Object o) {
//         // TODO Auto-generated method stub
//         // 没有使用泛型时需要类型判断
//         if(o instanceof Employee) {
//             Employee e = (Employee) o;
//             return this.name.compareTo(e.name);
//         }
//         return 0;
//     }
// }

class Employee implements Comparable<Employee>{
    int salary;
    int id;
    String name;
    @Override
    public int compareTo(Employee o) {
        // TODO Auto-generated method stub
        // 指明泛型时不需要类型判断
        return this.name.compareTo(o.name);
    }

    public static void main(String[] args) {
        TreeSet<Employee> treeSet = new TreeSet<>(new Comparator<Employee>() {
            // 使用泛型以后的写法
            public int compare(Employee o1, Employee o2) {
                return 0; 
            }
        });
    }
}
