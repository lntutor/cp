import java.util.Scanner;

/**
 * Created by loinguyen on 3/2/16.
 */
public class Main {

    public static String reverse(String sentence) {
        String [] array = sentence.split(" ");
        if(array.length<=1) return sentence;

        for(int i = 0; i < array.length/2; i++) {
            String tmp = array[i];
            array[i] = array[array.length - i - 1];
            array[array.length - i - 1] = tmp;
        }
        StringBuilder builder = new StringBuilder();
        for(String item: array) {
            builder.append(item + " ");
        }
        return builder.toString().trim();
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        for (int i = 1; i <=n; i++) {
            String line = scanner.nextLine();
            String result = String.format("Case #%d: %s", i, reverse(line));
            System.out.println(result);
        }

    }

}
