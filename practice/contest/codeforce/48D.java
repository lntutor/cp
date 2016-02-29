//http://codeforces.com/problemset/problem/48/D

import java.io.IOException;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        Map<Integer, Integer> mapOfNumber = new HashMap<>();//number & num of its occurrence
        int n = scanner.nextInt();
        int [] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        int [] copyOfArray = array.clone();
        Arrays.sort(copyOfArray);

        int tmp = 0;
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            if (i == 0 && copyOfArray[i] > 1) {
                System.out.println(-1);
                return;
            }

            if (copyOfArray[i] - tmp > 1) {
                System.out.println(-1);
                return;
            }

            if (!mapOfNumber.containsKey(copyOfArray[i])){
                mapOfNumber.put(copyOfArray[i], 1);
            } else {
                mapOfNumber.put(copyOfArray[i], mapOfNumber.get(copyOfArray[i]) + 1);
            }
            tmp = copyOfArray[i];
            if (max < copyOfArray[i]) max = copyOfArray[i];
        }


        if (max < n) max = n;

        List<List<Integer>> perms = new LinkedList<>();
        for (int i = 0; i < max; i++) {
            perms.add(new LinkedList<Integer>());
        }

        int numOfLastOccurence = Integer.MAX_VALUE;

        for (int i = 1; i <=max; i++) {
            if (mapOfNumber.get(i) == null) continue;;
            int key = i;
            int value = mapOfNumber.get(key);
            if (value > numOfLastOccurence) {
                System.out.println(-1);
                return;
            }

            for (int j = 0; j < value; j++) {
                perms.get(j).add(key);
            }
            numOfLastOccurence = value;
        }

        int [] result = new int[n];

        for (int i = 0; i <n; i++) {
            result[i] = 0;
        }

        int count = 0;

        int numOfPerm = 0;
        for (Iterator<List<Integer>> iterator = perms.iterator(); iterator.hasNext();) {
            List<Integer> string = iterator.next();
            if (string.isEmpty()) {
                // Remove the current element from the iterator and the list.
                iterator.remove();
            } else {
                numOfPerm++;
            }
        }
        for (List<Integer> list : perms) {
            for (Integer item : list) {
                for (int j = 0; j < n; j++) {
                    if (result[j]==0 && array[j] == item) {
                        result[j] = count + 1;
                        break;
                    }
                }
            }
            count++;
        }

        System.out.println(numOfPerm);
        for (int i = 0; i <n; i++) {
            if (i == n-1)
                System.out.print(result[i]);
            else
                System.out.print(result[i] + " ");
        }
    }
}
