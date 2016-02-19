// https://www.hackerrank.com/contests/w18/challenges/ghosts/submissions/code/4284508
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
    public static int gcd(int a, int b) {
        if (b>0) {
            return gcd(b, a%b);
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int A = in.nextInt();
        int B = in.nextInt();
        int C = in.nextInt();
        int D = in.nextInt();
        int result = 0;
        
/*
The difference between the town number and the street number is divisible by 3.
The sum of the street number and the house number is divisible by 5.
The product of the town number and the house number is divisible by 4.
The greatest common divisor of the town number and the apartment number is 1.
*/
        for (int a = 1; a <=A; a++) {
            for (int b = 1; b <=B; b++) {
                int diff = a - b;
                if (diff % 3 != 0) continue;
                for (int c = 1; c <=C; c++) {
                    int sum = b + c;
                    int product = a*c;
                    if (sum % 5 != 0 || product %4 !=0) continue;
                    for (int d = 1; d <=D; d++) {
                        int gcd = gcd(a, d);
                        if (gcd != 1) continue;
                        result+=1;
                    }
                }   
            }
        }
        System.out.println(result);
            
    }
}
