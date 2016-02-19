//http://codeforces.com/contest/597/problem/B
import java.io.IOException;
import java.util.*;

public class Main {

     public static class Pair {
        int left;
        int right;
        public Pair (int left, int right) {
            this.left = left;
            this.right = right;
        }
     }

    public static int solve(Pair[] list) {
        Stack<Pair> orders = new Stack<>();
        for (int i = 0; i < list.length; i++) {
            if (orders.size() == 0) orders.push(list[i]);
            Pair pair = orders.lastElement();
            if (pair.right < list[i].left) {
                orders.push(list[i]);
            }

        }
        int max = orders.size();
        orders.clear();
        for (int i = list.length -1; i >=0; i--) {
            if (orders.size() == 0) orders.push(list[i]);
            Pair pair = orders.lastElement();
            if (pair.left > list[i].right) {
                orders.push(list[i]);
            }

        }
        return orders.size() > max ? orders.size() : max;
    }

    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Pair[] list = new Pair[n];
        RESULT_TABLE = new int[n];

        for (int i = 0; i < n ; i++) {
            int left = scanner.nextInt();
            int right = scanner.nextInt();
            Pair pair = new Pair(left, right);
            list[i] = pair;
        }
        Arrays.sort(list, new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if (o1.left != o2.left) {
                    return o1.left - o2.left;
                } else {
                    return o1.right - o2.right;
                }
            }
        });
        System.out.println(solve(list));
    }
}
