package Basics;
public class Dog {
    private String name;
    private int age;

    public Dog(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void bark() {
        System.out.println("Woof from: " + name);
    }

    public void eat() {
        System.out.println("Yum from: " + name);
    }

    public void tellAge() {
        System.out.println("Age of " + name + " is " + age);
    }
}
