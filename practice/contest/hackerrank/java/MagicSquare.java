import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader ob = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(ob.readLine().trim());
        int [][] matrix = new int[n][n];
        int count = 0;
        int mainDigonal = 0;
        int antiDigonal = 0;

        Queue<Integer> result = new LinkedList<>();

        while(count < n) {
            String [] array = ob.readLine().split(" ");
            for (int j = 0; j < array.length; j++) {
                matrix[count][j] = Integer.parseInt(array[j]);
            }
            count++;
        }
        count = 0;
        for (int i = 0; i < n; i++) {
            mainDigonal += matrix[i][i];
            antiDigonal += matrix[n-1-i][i];
        }
        if (antiDigonal != mainDigonal) {
            count++;
            result.add(0);
        }

        int sumRow = 0;
        int sumColumn = 0;
        for (int i = 0; i < n; i++) {
            sumRow = 0;
            sumColumn = 0;
            for (int j = 0; j < n; j++) {
                sumRow+= matrix[i][j];
                sumColumn += matrix[j][i];
            }
            if (sumRow != mainDigonal){
                count++;
                result.add((i+1));
            }
            if (sumColumn != mainDigonal){
                count++;
                result.add(-(i+1));
            }
        }
        System.out.println(count);

        Collections.sort((List<Integer>) result, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1 - o2;
            };
        });
        for(Integer item : result) {
            System.out.println(item);
        }

    }
}