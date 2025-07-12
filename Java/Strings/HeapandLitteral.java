package Strings;

public class HeapandLitteral {

    public static void main(String[] args) {
        // String Literal
        String literal = "Hello, World!";
        System.out.println("String Literal: " + literal);

        // String Object(Heap Memory)
        String object = new String("Hello, Java!");
        System.out.println("String Object(Heap Memory): " + object);

        //Comparing String Literal and String Object
        String s1 = "Hello";
        String s2 = new String("Hello");
        if (s1 == s2) {
            System.out.println("s1 and s2 have the same reference.");
        } else {
            System.out.println("s1 and s2 have different references.");
        }
        if (s1.equals(s2)) {
            System.out.println("s1 and s2 have the same contents"); 
        }else{
            System.out.println("s1 and s2 have different contents");
    }

    if (s1.compareTo(s2) > 0) {
        System.out.println("s1 is greater than s2");
    } else if (s1.compareTo(s2) < 0) {
        System.out.println("s1 is less than s2");
    } else {
        System.out.println("s1 and s2 have the same content.");
    }
}
}
