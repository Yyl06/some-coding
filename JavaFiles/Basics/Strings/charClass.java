public class charClass {
    public static void main(String[] args) {
        //Character class methods
        char ch = 'A';
        System.out.println("Character: " + ch);
        System.out.println("Is Letter: " + Character.isLetter(ch));
        System.out.println("Is Digit: " + Character.isDigit(ch));
        System.out.println("Is Uppercase: " + Character.isUpperCase(ch));
        System.out.println("Is Lowercase: " + Character.isLowerCase(ch));
        System.out.println("To Lowercase: " + Character.toLowerCase(ch));
        System.out.println("To Uppercase: " + Character.toUpperCase(ch));

        //Comparing characters
        char ch1 = 'A';
        char ch2 = 'B';
        System.out.println("Comparing " + ch1 + " and " + ch2 + ": " + Character.compare(ch1, ch2));
        System.out.println("Is " + ch1 + " equal to " + ch2 + ": " + (ch1 == ch2));

        //Chars is digit
        char digit = '5';
        System.out.println("Is " + digit + " a digit: " + Character.isDigit(digit));
    }
}
