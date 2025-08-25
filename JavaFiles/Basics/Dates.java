
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class Dates {
    public static void main(String[] args) {
        Date date = new Date();
        SimpleDateFormat DateDay = new SimpleDateFormat("dd/mm/yy");

        Calendar timesCalendar = Calendar.getInstance();
        timesCalendar.setTime(date);

        System.out.println(timesCalendar);
        System.out.println(date);
    }
}
