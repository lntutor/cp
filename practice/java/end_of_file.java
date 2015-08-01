//https://www.hackerrank.com/challenges/java-end-of-file

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
        String s;
        int count = 1;
        while ((s = buf.readLine()) != null && s.length() > 0) {
            System.out.println(count + " " + s);
            count++;
        }
    }
}