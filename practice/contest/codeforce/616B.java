//http://codeforces.com/contest/616/problem/B

import java.io.IOException;
import java.math.BigInteger;
import java.util.*;

public class Main {


    public static BigInteger solve(int n) {
        BigInteger powerOfTwoSum = new BigInteger("0");
        int count = 0;
        while(true) {
            BigInteger powerOfTwo = new BigInteger(String.format("%.0f", Math.pow(2, count)));
            if (powerOfTwo.intValue() > n) {
                break;
            } else {
                powerOfTwoSum = powerOfTwoSum.add(powerOfTwo);
            }
            count++;
        }

        BigInteger two = new BigInteger("2");
        powerOfTwoSum = powerOfTwoSum.multiply(two);

        BigInteger result = new BigInteger("" + n);
        BigInteger tmp = new BigInteger("" + (n+1));

        result = result.multiply(tmp).divide(two);
        result = result.subtract(powerOfTwoSum);


        return result;
    }
    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(System.in);
        int row = scanner.nextInt();
        int col = scanner.nextInt();

        int result = Integer.MIN_VALUE;
        for (int i = 0; i < row; i++) {
            int minOfRow = Integer.MAX_VALUE;
            for (int j = 0; j < col; j++) {
                int temp = scanner.nextInt();
                if (temp < minOfRow) minOfRow = temp;
            }
            if (result < minOfRow) result = minOfRow;
        }
        System.out.println(result);

    }
}
