//http://codeforces.com/problemset/problem/46/C
// Hamster and Tiger
import java.io.IOException;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        String line = scanner.nextLine();
        char[] chars = line.toCharArray();
        Arrays.sort(chars);
        String sorted = new String(chars);

        int answer = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j<n; j++) {
                if (sorted.charAt(j) != line.charAt(j)) {
                    count++;
                }
            }
            if (answer > count/2) answer = count/2;
            sorted = sorted.substring(1, sorted.length()) + sorted.charAt(0);
        }
        System.out.println(answer);
    }
}
