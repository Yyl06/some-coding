import java.util.Scanner;

public class StudentRegSys {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a Book: ");
        String title = sc.nextLine();

        String availableTitle = title.concat(" - Available");
        System.out.println("Concatenated Title: " + availableTitle);

        if(title.length() >= 5){
            System.out.println("Substring: " + title.substring(0, 5));
        }else{
            System.out.println("Title too short for substring (needs at least 5 characters).");
        }

        int firstIndex = title.indexOf("Java");
        int lastIndex = title.lastIndexOf("Java");

        if (firstIndex != -1) {
            System.out.println("First occurrence of 'Java' at index: " + firstIndex);
            System.out.println("Last occurrence of 'Java' at index: " + lastIndex);
        } else {
            System.out.println("'Java' not found in title.");
        }

        System.out.println("Characters In the Index: ");
        for(int i = 0 ; i < title.length() ; i++){
            System.out.println("Index: " + i + ": " + title.charAt(i));
        }
        sc.close();
    }
    
}
