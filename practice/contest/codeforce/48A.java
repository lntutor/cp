//http://codeforces.com/problemset/problem/48/A

import java.io.IOException;
import java.util.*;

public class Main {

    public static String solve(int a, int b, int c) {
        if (a == b && b == c) return "?";
        if (a != b && b != c && c != a) return "?";

        if (a == b) {
            if (c - a == 1 || c - a == -2) return "S";
            else return "?";
        }else if (a == c) {
            if (b - a == 1 || b - a == -2) return "M";
            else return "?";
        }else {

            if (a - b == 1 || a - b == -2) return "F";
            else return "?";
        }

    }

    public static int convertToInt(String value) {
        if (value.equalsIgnoreCase("rock")) return 1;
        else if (value.equalsIgnoreCase("paper")) return 2;
        else return 3;
    }
    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(System.in);
        String F = scanner.nextLine();
        String M = scanner.nextLine();
        String S = scanner.nextLine();
        System.out.println(solve(convertToInt(F), convertToInt(M), convertToInt(S)));

    }
}
