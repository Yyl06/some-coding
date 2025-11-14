import java.util.ArrayList;

/*Lab Skill 3 - Question 1
Name : Yong Yuan Lin
Date : 11 September 2025*/

public class LabSkill3Question1{
    public static void main(String[] args) {
        ArrayList<String> animal = new ArrayList<>();
        animal.add("Kangaroo");
        animal.add("Cow");
        animal.add("Sheep");
        animal.add("Snake");
        animal.add("Buffalo");
        animal.add("Camel");
        animal.add("Giraffe");
        animal.add("Cat");
        animal.add("Dog");
        animal.add("Monkey");

        System.out.println("Size List Animal: " + animal.size());

        System.out.println("Animal List Array: ");
        for(int i = 0; i < animal.size(); i++){
            System.out.print("| " + animal.get(i));
        }
        System.out.println(" | ");

        if(animal.contains("Camel")){
            System.out.println("The Element 'Camel' is found in the list.");
        }
        if(animal.contains("Spider")){
            System.out.println("The Element 'Spider' is found in the list.");
        }
        if(!animal.contains("Spider") || !animal.contains("Camel")){
            System.out.println("The element is not found in the list");
        }

        int index = animal.indexOf("Giraffe");
        if(index != -1){
            animal.add(index, "Dolphin");
        }
        System.out.println("Animal List after add Dolphin : " + animal);

        animal.remove("Snake");
        animal.remove("Dog");
        animal.removeFirst();
        System.out.println("Animal List after removal :" + animal);

        System.out.println("The location of 'Monkey' is at index " + animal.indexOf("Monkey"));

        index = animal.indexOf("Cat");
        animal.set(index, "Hamster");
        System.out.println("Animal List After Replace: " + animal);

        if(animal.isEmpty()){
            System.out.println("List Is Empty.");
        }else{
            System.out.println("List is not Empty");
        }

        String data1 = animal.get(4);
        String data2 = animal.get(6);
        int result = data1.compareTo(data2);
        if (result < 0) {
            System.out.println(data1 + " comes before " + data2);
        } else if (result == 0) {
            System.out.println(data1 + " and " + data2 + " are equal.");
        } else {
            System.out.println(data1 + " comes after " + data2);
        }

        String dataNew = animal.get(3);
        if (dataNew.endsWith("y")) {
            System.out.println("Ends with Y");
        } else {
            System.out.println("Not Ends with Y");
        }

        System.out.println("Animal List before clear : " + animal);
        System.out.println("Performing Clear Operation..");
        animal.clear();
        System.out.println("Animal List after clear : " + animal);
    }
}