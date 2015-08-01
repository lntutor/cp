import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.util.Scanner;

public class Solution {
    
    public static void printLexico(String string, int n) {
        String min = string.substring(0, n);
        String max = string.substring(0, n);
        for (int i = 0; i < string.length() - n + 1; i ++) {
            String tmp = string.substring(i, i + n);
            if (tmp.compareTo(max) > 0) max = tmp;
            if (min.compareTo(tmp) > 0) min = tmp;
        }
        System.out.println(min);
        System.out.println(max); 
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int count = 0;
        String line = "";
        int n = 0;
        while (scanner.hasNext()) {
            if (count == 0) {
                line = scanner.next();
            } else {
                n = Integer.parseInt(scanner.next());
            }
            count++;
        }
        printLexico(line, n);
    }
}