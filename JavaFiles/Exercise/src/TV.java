public class TV{
    int channel;
    int volumeLevel;
    boolean on;

    public TV(){
        channel = 1;
        volumeLevel = 1;
        on = false;
    }

    public static void main(String[] args) {
        TV television = new TV();
        television.turnOn();
        television.setChannel(2);
        television.setVolume(5);
        System.out.println("Channel Right now: " + television.channel + "\nVolume right now: " + television.volumeLevel);

        TV Nickelodean = new TV();
        Nickelodean.turnOn();
        Nickelodean.setChannel(130);
        Nickelodean.setVolume(8);
        System.out.println("Nickelodean TV is on Channel: " + Nickelodean.channel + " and volume level is: " + Nickelodean.volumeLevel);
    }

    public void turnOn(){
        on = true;
    }
    public void turnOff(){
        on = false;
    }

    public void setChannel(int newChannel){
        if (newChannel > 121 || newChannel < 1){
            System.err.println("Invalid range of Channel");
        }else{
            channel = newChannel;
        }
    }

    public void setVolume(int newVolume){
        if(newVolume >= 7 || newVolume < 1){
            System.err.println("Invalid range of Volume");
        }else{
            volumeLevel = newVolume;
        }
    }

    public void channelUp(){
        channel--;
    }
    public void channelDown(){
        channel++;
    }
    public void volumeUp(){
        volumeLevel++;
    }
    public void volumeDown(){
        volumeLevel--;
    }
}