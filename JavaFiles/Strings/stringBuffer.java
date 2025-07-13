public class stringBuffer {
    public static void main(String[] args) {
        StringBuffer sb = new StringBuffer("Hello");
        System.out.println("Original: " + sb);

        // Append
        sb.append(" World");
        System.out.println("After Append: " + sb);

        // Insert
        sb.insert(5, ",");
        System.out.println("After Insert: " + sb);

        // Delete
        sb.delete(5, 6);
        System.out.println("After Delete: " + sb);

        // Reverse
        sb.reverse();
        System.out.println("After Reverse: " + sb);
    }
}
