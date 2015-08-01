import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.Scanner;

public class Main {

    public static void main(String []args) {
        
        Scanner in = new Scanner(System.in);
        while(in.hasNext()) {
            String IP = in.next();
            System.out.println(IP.matches("[0-9].[0-9].[0-9].[0-9]"));
        }

    }
}