//http://codeforces.com/contest/569/problem/A
import java.io.IOException;
import java.util.*;

public class Main {


    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(System.in);
        double T = scanner.nextInt();
        double S = scanner.nextInt();
        double q = scanner.nextInt();

        double currentDownloaded = S;
        double numOfPlay = 0;
        double velocity = (q-1)/q;
        while(currentDownloaded + 0.1 < T) {
            numOfPlay++;
            double extra = currentDownloaded*velocity;
            while(extra > 0.0000001) {
                currentDownloaded += extra;
                extra = extra*velocity;
                if (currentDownloaded >= T - 0.1) break;
            }
        }
        System.out.println(String.format("%.0f", numOfPlay));


    }
}
