//http://codeforces.com/problemset/problem/79/B
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        int t = in.nextInt();
        long [] wasted = new long[k];

        int i;
        int row, col;
        for(i = 0; i < k; ++i) {
            row = in.nextInt();
            col = in.nextInt();
            wasted[i] = m * (row -1) + (col -1);
        }

        Arrays.sort(wasted);

        for(i = 0; i < t; ++i) {
            row = in.nextInt();
            col = in.nextInt();
            long cellNumber = (int) m * (row -1) + (col -1);

            int index = 0;

            while (index < k) {
                if (wasted[index] < cellNumber) ++index;
                else break;
            }
            if (index < wasted.length && wasted[index] == cellNumber)
                System.out.println("Waste");
            else {
                if (index < wasted.length -1 && cellNumber > wasted[index]) index++;
                int type = (int) (cellNumber - index) % 3;
                switch (type) {
                    case 0:
                        System.out.println("Carrots");
                        break;
                    case 1:
                        System.out.println("Kiwis");
                        break;
                    case 2:
                        System.out.println("Grapes");
                        break;
                    default:
                        System.out.println("Waste");
                        break;
                }
            }
        }

    }
}