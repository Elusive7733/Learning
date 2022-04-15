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

        Dog.dogStatic(); //this is only possible because of static funtion
        // myDog.dogStatic(); // this throws a warning as method should be accessed in a static way

        int largeNumber = 123_456_789; //seperate digits with _
        long verylargeNumber = 3_123_456_789L; //add the L suffix to let java know it is a long number

        float decimalNumber = 10.99F; //add the F suffix to let java know it is a float number

        double largeDecimalNumber = 1000.9999; //F is only required for float because by default java consideres the number as double
    }

    //private function

    //Static Method means you can call this function without creating an object of this class
    private static void callCat() {
        Cat.meow();
    }


}
