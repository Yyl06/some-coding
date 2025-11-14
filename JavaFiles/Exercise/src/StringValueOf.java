public class StringValueOf {
public static void main(String[] args) {
int num = 123;
double price = 45.67;
char grade = 'A';

String s1 = String.valueOf(num);
String s2 = String.valueOf(price);
String s3 = String.valueOf(grade);

System.out.println("Number as String: " + s1);
System.out.println("Price as String: " + s2);
System.out.println("Grade as String: " + s3);
}
}