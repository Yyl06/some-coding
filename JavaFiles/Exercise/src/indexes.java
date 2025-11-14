abstract class Rental{
    protected String rentalNum;

    public Rental(String rentalNum){
        this.rentalNum = rentalNum;
    }

    public void setRentalNum(String rentalNum){
        this.rentalNum = rentalNum;
    }

    abstract public double getRentalRate();
}

class HotelRoom extends Rental implements Comparable<HotelRoom>{
    private int roomID;
    private String roomTypes;

    public HotelRoom(String rentalNum, int roomID, String roomTypes) {
        super(rentalNum);
        this.roomID = roomID;
        this.roomTypes = roomTypes;
    }

    public int getRoomID(){
        return roomID;
    }

    public String getRoomTypes(){
        return roomTypes;
    }

    @Override
    public double getRentalRate(){
        if(roomTypes.equalsIgnoreCase("Deluxe")){
            return 300.00;
        }else if(roomTypes.equalsIgnoreCase("Executive Deluxe")){
            return 350.00;
        }else if(roomTypes.equalsIgnoreCase("Junior Suite")){
            return 400.00;
        }else if(roomTypes.equalsIgnoreCase("Club Room")){
            return 410.00;
        }
        return 0.00;
    }

    @Override
    public int compareTo(HotelRoom hotel){
        return (int) (this.getRentalRate() - hotel.getRentalRate());
    }

    @Override
    public String toString(){
        return "Rental Number: " + rentalNum + 
        "\nRoomID: " + roomID +
        "\nRoom Types: " + roomTypes + 
        "\nRental Rate: " + getRentalRate() + "\n";
    }
}



public class indexes {
    public static void main(String[] args) {
        HotelRoom ob1 = new HotelRoom("A001", 0001, "Deluxe");
        HotelRoom ob2 = new HotelRoom("A002", 0002, "Club Room");

        System.out.println(ob1.toString() + "\n" + ob2.toString() + "\nComparison: " + ob1.compareTo(ob2));
    }


    public int findSmallest(int[] arr){
        int smallest = arr[0];
        for(int i = 0 ; i < arr.length; i++){
            if(smallest > arr[i]) smallest = arr[i];
        }
        return smallest;
    }
}