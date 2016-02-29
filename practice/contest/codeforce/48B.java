//http://codeforces.com/problemset/problem/48/B

import java.io.IOException;
import java.util.*;

public class Main {

    public static int solve(int[][] matrix, int n, int m, int a, int b) {

        int maxZero = Integer.MIN_VALUE;
        //search for a*b in n*m matrix

        for (int i = 0; i <= n - a; i++) {
            for (int j = 0; j <= m - b; j++) {
                int tmp = 0;
                for (int k = i; k < i + a; k++) {
                    for (int l = j; l < j + b; l++) {
                        if (matrix[k][l] == 0) tmp++;
                    }
                }
                if (tmp > maxZero) maxZero = tmp;
            }
        }


        //search for b*a in n*m matrix
        for (int i = 0; i <= n - b; i++) {
            for (int j = 0; j <= m - a; j++) {
                int tmp = 0;
                for (int k = i; k < i + b; k++) {
                    for (int l = j; l < j + a; l++) {
                        if (matrix[k][l] == 0) tmp++;
                    }
                }
                if (tmp > maxZero) maxZero = tmp;
            }
        }
        return a*b - maxZero;
    }

    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int [][] matrix = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        System.out.println(solve(matrix, n, m, a, b));
    }
}
