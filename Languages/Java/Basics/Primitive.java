package Basics;

public class Primitive {

    public static void main(String[] args) {
        byte age = 127;
        // byte bigAge = 128; //Error becuase byte can have upto 127 (in decimal)

        int largeNumber = 123_456_789; //seperate digits with _
        long verylargeNumber = 3_123_456_789L; //add the L suffix to let java know it is a long number
        float decimalNumber = 10.99F; //add the F suffix to let java know it is a float number
        double largeDecimalNumber = 1000.9999; //F is only required for float because by default java consideres the number as double
        char letter = 'a';
        boolean isAuth = false;

        final int constantVariable = 12;
    }
    
}
