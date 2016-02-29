//https://www.hackerrank.com/contests/2014-icpc-northwestern-european-regional-practice/challenges/judging-troubles

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader ob = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(ob.readLine());
        Map<String, Integer> map1 = new HashMap<>();
        int other = 0;
        for (int i = 0; i < n; i++) {
            String item = ob.readLine();
            if (map1.get(item) != null) {
                map1.put(item, (Integer) map1.get(item) + 1);
            } else {
                map1.put(item, 1);
            }
        }

        Map<String, Integer> map2 = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String item = ob.readLine();
            if (map2.get(item) != null) {
                map2.put(item, (Integer) map2.get(item) + 1);
            } else {
                map2.put(item, 1);
            }
        }
        int result = 0;
        for (Map.Entry<String, Integer> entry : map1.entrySet())
        {
            Integer value = map1.get(entry.getKey()) != null ? map1.get(entry.getKey()) : 0;
            Integer value1 = map2.get(entry.getKey()) != null ? map2.get(entry.getKey()) : 0;
            if (value > value1) value = value1;
            result += value;
        }
        System.out.println(result);

    }
}