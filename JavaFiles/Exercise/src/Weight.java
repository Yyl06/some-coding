class BMI implements Comparable<BMI>{
    private String ID;
    private double weight;
    private double height;

    public BMI(){
        this.ID = "A001";
        this.weight = 25.5;
        this.height = 1.75;
    }

    public void setData(String ID, double weight, double height){
        this.ID = ID;
        this.weight = weight;
        this.height = height;
    }

    public String getID(){
        return ID;
    }

    public double getWeight(){
        return weight;
    }

    public double getHeight(){
        return height;
    }

    public double calculateBMI(){
        if(height > 2) height = height/100;
        return weight / Math.pow(height, height);
    }

    public String determineStatus(){
        double newBMI = calculateBMI();
        if(newBMI < 18.5){
            return "Underweight";
        }else if(newBMI >= 18.5 && newBMI <= 24.9){
            return "Normal";
        }else if(newBMI >= 25.0 && newBMI <= 29.9){
            return "Overweight";
        }else if(newBMI >= 30.0){
            return "Obese";
        }else{
            return "Error Calculation";
        }
    }

    @Override
    public int compareTo(BMI other){
        return (int) (this.calculateBMI() - other.calculateBMI());
    }

    @Override
    public String toString(){
        return "\nID: " + ID + 
        "\nWeight: " + weight + 
        "\nHeight: " + height +
        "\nBMI: " + calculateBMI() + " " +  determineStatus() + "\n"; 
    }
}


public class Weight {
    public static void main(String[] args) {
        BMI ob1 = new BMI();
        BMI ob2 = new BMI();
        ob1.setData("A001", 75, 1.73);
        ob2.setData("A002", 65, 1.75);

        System.out.println("Object 1: " + ob1.toString() + "\nObject 2: " + ob2.toString() + "\nComparison: " + ob1.compareTo(ob2));
    }
}
