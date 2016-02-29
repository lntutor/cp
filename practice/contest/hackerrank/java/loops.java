import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Main {
    
    public static void printArray(int[] array, int n) {
        for (int i = 0; i < n; i ++) {
            System.out.print(array[i]);
            if (i != n-1 ) {
                System.out.print(" ");
            } else {
                System.out.println();
            }
        }
    }
    
    public static int[] calc(int a, int b, int n) {
        int [] result = new int [n];
        int lastSum = 0;
        for (int i = 0; i < n; i ++) {
            if (i==0) {
                result[i] = a + b;
                lastSum = result[i];
            } else {
                result[i] = lastSum + (int)(b*Math.pow(2, i));
                lastSum = result[i];
            }
        }
        printArray(result, n);
        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
        String line;
        int count = 0;
        while ((line = buf.readLine()) != null && line.length() >0) {
            if (count == 0) {
                int n = Integer.parseInt(line);
            } else {
                String [] array = line.split(" ");
                int a = Integer.parseInt(array[0]);
                int b = Integer.parseInt(array[1]);
                int n = Integer.parseInt(array[2]);
                calc(a,b,n);
            }
            count++;
        }
    }
}