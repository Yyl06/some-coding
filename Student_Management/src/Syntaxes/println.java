package Syntaxes;

public class println {
    public static void printline(Object msg){
        System.out.println(msg);
    }
    public static void print(Object msg){
        System.out.print(msg);
    }
    public static void error(Object msg){
        System.err.print("msg");
    }
    public static void errorline(Object msg){
        System.err.println(msg);
    }
}
