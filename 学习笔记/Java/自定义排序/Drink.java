package 学习笔记.Java.自定义排序;

import java.util.Arrays;
import java.util.Comparator;


public class Drink implements Comparable<Drink> { //实现的是Comparable接口
    double price;
    String producers;
    int total;

    public Drink() {

    }

    public Drink(String producers, double price) {
        this.producers = producers;
        this.price = price;
    }


    @Override
    public int compareTo(Drink o) { //接口中所有的方法都是public
        // return Double.compare(this.price, o.price); //使用静态Double.compare方法
        return (int)(this.price - o.price); //类型强转
    }


    public static void main(String[] args) {
        //compare
        Drink[] drinks = new Drink[4];
        drinks[0] = new Drink("Cola", 3);
        drinks[1] = new Drink("RedBull", 6);
        drinks[2] = new Drink("Claw", 5);
        drinks[3] = new Drink("Lucking", 10);
        Arrays.sort(drinks); //因为这个类本身实现了comparable接口所以可以用Arrays.sort()
        for (Drink d : drinks) {
            System.out.println(d.price + " " + d.producers);
        }


        System.out.println("-----------------");

        //comparator
        //通过自己构造一个comparator在Arrays.sort()中使用
        Arrays.sort(drinks, new DrinkComparator());
        for (Drink d : drinks) {
            System.out.println(d.price + " " + d.producers);
        }


        System.out.println("-----------------");

        //lambda表达式
        Arrays.sort(drinks, (d1, d2) -> {
            if (d1.price == d2.price) {
                return d2.producers.compareTo(d1.producers);
            } else {
                return Double.compare(d2.price, d1.price);
            }
        }); //标准格式
        for (Drink d : drinks) {
            System.out.println(d.price + " " + d.producers);
        } //comparator是一个只有一个方法的接口所以可以提供一个lambda表达式

    }
}

class DrinkComparator implements Comparator<Drink> { //实现的是Comparator接口
    @Override
    public int compare(Drink d1, Drink d2) { //实现compare方法，两个参数
        return d1.producers.compareTo(d2.producers);
    }
}
