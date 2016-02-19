// https://www.hackerrank.com/contests/2014-icpc-northwestern-european-regional-practice
import java.io.*;

public class Solution {

    static int MAX_PRODUCT = 2024;
    static int MAX_DIVIDER = 64;

    private static int [][] dp = new int[MAX_PRODUCT][MAX_DIVIDER];
    private static int [] savedSum = new int[MAX_PRODUCT];

    public static int min(int a, int b) {
        return a < b ? a : b;
    }

    public static int rounded(int v) {
        return ((v + 5) / 10) * 10;
    }


    public static int calc(int [] price, int n, int d) {
        if (n == 0) return 0;
        if (d == 0) return rounded(savedSum[n]);

        if (dp[n][d] != -1) return dp[n][d];

        int res = Integer.MAX_VALUE;
        for (int index = 0; index < n; index++) {
            dp[index][d-1] = calc(price, index, d-1);
            res = min(res, dp[index][d-1] + rounded(savedSum[n] - savedSum[index]));
        }
        return res;
    }

    private static void resetData(){
        for (int i = 0; i < MAX_PRODUCT; i++)
            savedSum[i] = 0;
        for (int i = 0; i < MAX_PRODUCT; i++)
            for (int j = 0; j < MAX_DIVIDER; j++)
                dp[i][j] = -1;
    }

    public static void main(String[] args) throws IOException {
        resetData();
        BufferedReader ob = new BufferedReader(new InputStreamReader(System.in));
        String [] line = ob.readLine().split(" ");
        int product = Integer.parseInt(line[0]);
        int divider = Integer.parseInt(line[1]);
        line = ob.readLine().split(" ");
        int [] array = new int[product];


        for (int i = 0; i < product; i++){
            array[i] = Integer.parseInt(line[i]);

        }

        savedSum[0] = 0;
        for (int i = 1; i <= product; i++){
            if (i==1)
                savedSum[i] = array[i-1];
            else
                savedSum[i] = savedSum[i-1] + array[i-1];
        }

        int result = calc(array, array.length, divider);
        System.out.println(result);
    }

    private static void printArray(int [] array) {
        for (int i = 0; i < array.length; i++)
            System.out.println(array[i]);
    }
}