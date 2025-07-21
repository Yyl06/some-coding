public class statics{
    //Static variable
    static int count = 0;

    //Static method
    public static void incrementCount() {
        count++;
    }

    //Static constant
    public static final int MAX_INSTANCES = 100;

    public static void displayCount() {
        System.out.println("Number of instances created: " + count);
    }
}
