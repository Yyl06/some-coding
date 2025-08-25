import java.util.Calendar;
public class WeekendCheck {
public static void main(String[] args) {
Calendar cal = Calendar.getInstance();
int dayOfWeek = cal.get(Calendar.DAY_OF_WEEK);
if (dayOfWeek == Calendar.SATURDAY || dayOfWeek == Calendar.SUNDAY) {
System.out.println("Today is a weekend!");
} else {
System.out.println("Today is a weekday.");
}
}
}