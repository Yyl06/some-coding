public class functionality{
    public static void main(String[] args){
        //Length of a String
        String str = "Hello World!";
        int result = str.length();
        System.out.println("Length of the string: " + result);
        //or
        System.out.println("Length of the string: " + str.length());

        //Extracting a single char
        System.out.println("First character: " + str.charAt(0));

        //Concatenation of Strings
        String str2 = " How are you?";
        System.out.println("Concatenated String: " + str.concat(str2));

        //Extracting a substring
        System.out.println("Substring: " + str.substring(0, 5));

        //Converting to uppercase
        System.out.println("Uppercase: " + str.toUpperCase());

        //Converting to lowercase
        System.out.println("Lowercase: " + str.toLowerCase());

        //Replacing characters
        System.out.println("Replaced String: " + str.replace('o', 'a'));

        //Replace first occurrence
        System.out.println("Replaced First Occurrence: " + str.replaceFirst("o", "O"));

        //Replace string
        System.out.println("Replaced String: " + str.replace("World", "Java"));

        //Replacing all occurrences
        System.out.println("Replaced All Occurrences: " + str.replaceAll("o", "O"));

        //Checking if string starts with a prefix
        System.out.println("Starts with 'Hello': " + str.startsWith("Hello"));

        //Checking if string ends with a suffix
        System.out.println("Ends with 'World!': " + str.endsWith("World!"));

        //Finding the index of a character
        System.out.println("Index of 'o': " + str.indexOf('o'));

        //Finding the last index of a character
        System.out.println("Last index of 'o': " + str.lastIndexOf('o'));

        //Trimming whitespace
        String str3 = "   Hello World!   ";
        System.out.println("Trimmed String: '" + str3.trim() + "'");
    }
}