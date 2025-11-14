public class test2 {
    public static void main(String[] args) {
        //String class explanation
        String s1 = "Hello"; //string literal, stored in string pool
        String s2 = new String("Hello World"); //create a new object in heap memory
        System.out.println(s1 == s2); // false, compares memory addresses
        System.out.println(s1.equals(s2)); // true, compares content
        System.out.println(s1.length()); // 5, length of the string
        System.out.println(s1.charAt(1)); // 'e', character at index 1
        System.out.println(s1.substring(1, 4)); // "ell", substring from index 1 to 4
        System.out.println(s1.indexOf('l')); // 2, index of first occurrence of 'l'
        System.out.println(s1.toUpperCase()); // "HELLO", convert to uppercase
        System.out.println(s1.toLowerCase()); // "hello", convert to lowercase
        System.out.println(s1.replace('l', 'x')); // "Hexxo", replace 'l' with 'x'
        System.out.println(s1.trim()); // "Hello", remove leading and trailing spaces
        System.out.println(s1.concat(" World")); // "Hello World", concatenate strings

        String[] parts = s1.split("e"); // split string by 'e'
        for(String part : parts) {
            System.out.println(part); // prints "H" and "llo"
        }

        //StringBuilder
        StringBuilder sb = new StringBuilder(); // mutable string
        sb.append("Hello"); // append string, add behind
        sb.append(" World");
        System.out.println(sb.toString()); // "Hello World"

        sb.insert(5, ","); // insert string at index 5
        System.out.println(sb.toString()); // "Hello, World"

        sb.replace(5, 6, "!"); // replace substring from index 5 to
        System.out.println(sb.toString()); // "Hello! World"

        sb.delete(5, 6); // delete substring from index 5 to 6
        System.out.println(sb.toString()); // "Hello World"

        sb.reverse(); // reverse the stringa
        System.out.println(sb.toString()); // "dlroW olleH"

        String finalString = sb.toString(); // convert StringBuilder to String
        System.out.println(finalString); // "dlroW olleH"

        //Character class, a Wrapper class
        char ch = 'a';
        Character chObj = Character.valueOf(ch); // autoboxing
        char chPrimitive = chObj.charValue(); // unboxing
        System.out.println(chPrimitive); // 'a'
        System.out.println(Character.isDigit(ch)); // false, check if digit
        System.out.println(Character.isLetter(ch)); // true, check if letter
        System.out.println(Character.isWhitespace(' ')); // true, check if whitespace
        System.out.println(Character.toUpperCase(ch)); // 'A', convert to uppercase
        System.out.println(Character.toLowerCase('A')); // 'a', convert to lowercase
    }
}
