//http://codeforces.com/contest/616/problem/E

import java.io.IOException;
import java.util.*;

public class Main {

    public static int[][][] dp ;//= new int[30][30][50];
    public static int MAX = 310;

    public static void solve() {
        dp = new int [MAX+1][MAX+1][55];

        for (int i = 1; i <=31; i++) {
            for (int j = 1; j <= 31; j++) {
                int kmax = Math.min(50, i * j);
                for (int k = 0; k <= kmax; k++) {
                    dp[i][j][k] = Integer.MAX_VALUE;
                }
            }
        }

//        for (int i = 1; i <=30; i++) {
//            for (int j = 1; j <=30; j++) {
//                int kmax = Math.min(50, i*j);
//                dp[i][j][0] = 0;
//                for (int k = 1;k <= kmax;k++) {
//                    if (i * j == k) {
//                        dp[i][j][k] = 0;
//                        continue;
//                    }
//                    for (int ck = 0; ck <= k; ck++) {
//                        for (int lk = 0;lk <= k;lk++){
//                            for (int ni = 1;ni < i;ni++)
//                                dp[i][j][k] = Math.min(dp[i][j][k],dp[ni][j][lk]+dp[i-ni][j][k-lk]+j*j);
//                            for (int nj = 1;nj < j;nj++)
//                                dp[i][j][k] = Math.min(dp[i][j][k],dp[i][nj][lk]+dp[i][j-nj][k-lk]+i*i);
//                        }
//                    }
//                }
//            }
//        }

        for (int i = 1;i <= 30;i++)
            for (int j = 1;j <= 30;j++){
                int kmax = Math.min(50, i * j);
                dp[i][j][0] = 0;
                for (int k = 1;k <= kmax;k++){
                    if (k == i*j){
                        dp[i][j][k] = 0;
                        continue;
                    }
                    for (int lk =0 ; lk <= k;lk++){
                        for (int ni = 1;ni < i;ni++)
                            dp[i][j][k] = Math.min(dp[i][j][k], dp[ni][j][lk] + dp[i - ni][j][k - lk] + j * j);
                        for (int nj = 1;nj < j;nj++)
                            dp[i][j][k] = Math.min(dp[i][j][k], dp[i][nj][lk] + dp[i][j - nj][k - lk] + i * i);
                    }
                }
            }
    }
    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(System.in);
        int numOfTest = scanner.nextInt();

        int result = Integer.MIN_VALUE;
        solve();
        for (int i = 0; i < numOfTest; i++) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int k = scanner.nextInt();
            System.out.println(dp[n][m][k]);
        }

    }
}
