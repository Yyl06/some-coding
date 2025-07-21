public class convertToNum{
    public static void main(String[] args) {
        //Convert to Int
        String str = "123";
        int num = Integer.parseInt(str);
        System.out.println("The number is: " + num);

        //Convert to Double
        String strDouble = "123.45";
        double numDouble = Double.parseDouble(strDouble);
        System.out.println("The double number is: " + numDouble);

        //String to Int/Double with error handling
        String invalidStr = "abc";
        try {
            int invalidNum = Integer.parseInt(invalidStr);
            System.out.println("The number is: " + invalidNum);
        }catch(NumberFormatException e){
            System.out.println("Error: Cannot convert '" + invalidStr + "' to an integer.");
        }
    }
}
