public class passByvalue {
    public static void main(String[] args) {
        int originalValue = 5;
        System.out.println("Before: " + originalValue);
        modifyValue(originalValue);
        System.out.println("After: " + originalValue);
    }

    public static void modifyValue(int value) {
        value = 10;
        System.out.println("Inside modifyValue: " + value);
    }
}
