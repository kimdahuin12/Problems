import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
class Main {
    public static void main(String[] args) {
        String date = LocalDate.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd"));
        System.out.println(date);
    }
}
