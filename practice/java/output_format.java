//https://www.hackerrank.com/challenges/java-output-formatting

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
        String s;
        System.out.println("================================");
        ArrayList<String> array = new ArrayList<String>();
        String format = "%-15s%03d";
        while ((s = buf.readLine()) != null && s.length() > 0) {
            String[]data = s.split(" ");
            
            System.out.println(String.format(format, data[0], Integer.parseInt(data[1])));
        }
        System.out.println("================================");
    }
}