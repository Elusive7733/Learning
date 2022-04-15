package Basics;
import java.util.Scanner;

class test {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Hello World");
        System.out.println("Enter a number: ");

        int num = input.nextInt();
        System.out.println("You entered: " + num + "\n\n");

        input.close();

        //Checking String Equality
        String myName = "Geobo masataka";
        System.out.println(myName.contentEquals("Geobo masataka") + "\n\n");

        //Calling a function from another class
        callCat();

        System.out.println("\n");


        //creating an object in another class
        Dog myDog = new Dog("Fido", 3);
        myDog.bark();
        Dog hibasDog = new Dog("Fluffy", 2);
        hibasDog.eat();

        myDog.tellAge();
        hibasDog.tellAge();

    }

    //private function
    private static void callCat() {
        Cat.meow();
    }


}
