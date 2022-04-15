package Stings;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
    
        Scanner input = new Scanner(System.in);
        System.out.print("Enter String: ");
        String myString = input.nextLine().trim();

        System.out.println(myString);

        input.close();

        // System.out.println(false & false);
        // System.out.println(false & true);
        // System.out.println(true & false);
        // System.out.println(true & true);
        // System.out.println("\n");
        // System.out.println(false && false);
        // System.out.println(false && true);
        // System.out.println(true && false);
        // System.out.println(true && true);
    }
}
