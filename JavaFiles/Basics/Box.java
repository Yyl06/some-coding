import javax.swing.JOptionPane;

public class Box{
    public static void main(String[] args) {
        System.out.println("Hello World");
        showBox();
        System.exit(0);
    }
    public static void showBox(){
        JOptionPane.showMessageDialog(null, "Hello World", "Hello World", JOptionPane.WARNING_MESSAGE);
    }
    
}
