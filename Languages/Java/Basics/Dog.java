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

    public static void dogStatic() {
        System.out.println("This is a Static method from Dog");
        // can not use name, age as it is a non static field
    }
}
