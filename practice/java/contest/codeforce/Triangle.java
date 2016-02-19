//http://codeforces.com/problemset/problem/6/A

import java.io.IOException;
import java.util.Scanner;
import java.util.Stack;

public class Main {

    private static String TRIANGLE = "TRIANGLE";
    private static String SEGMENT = "SEGMENT";
    private static String IMPOSSIBLE = "IMPOSSIBLE";

    private static String getTriangleInfo(int a, int b, int c) {
        if (a + b < c || a + c < b || b + c < a) return IMPOSSIBLE;
        if (a + b == c || a + c == b || b + c == a) return SEGMENT;
        return TRIANGLE;
    }


    private static String getTriangleInfo(int a, int b, int c, int d) {
        String first = getTriangleInfo(a, b ,c);
        String second = getTriangleInfo(a, b ,d);
        String third = getTriangleInfo(a, c ,d);
        String fourth = getTriangleInfo(b, c ,d);

        if (first == TRIANGLE || second == TRIANGLE || third == TRIANGLE || fourth == TRIANGLE) return TRIANGLE;

        if (first == SEGMENT || second == SEGMENT || third == SEGMENT || fourth == SEGMENT) return SEGMENT;
        return IMPOSSIBLE;

    }
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();
        System.out.println(getTriangleInfo(a, b ,c , d));
    }
}
