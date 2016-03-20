//https://www.hackerrank.com/challenges/string-reduction
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Main {
    /* Head ends here */
    static boolean checkIsSame(String a) {
        for(int i = 0; i < a.length()-1; i++) {
            if (a.charAt(i) != a.charAt(i+1)) return false;
        }
        return true;
    }
    static int stringReduction(String a) {
        if (checkIsSame(a)) return a.length();

        int array[] = new int [3];
        for(char c : a.toCharArray()) {
            array[c - 'a']++;
        }

        if (array[0]%2 == 0 && array[1]%2==0 && array[2]%2==0) return 2;
        if (array[0]%2 == 1 && array[1]%2==1 && array[2]%2==1) return 2;
        return 1;
    }

    /* Tail starts here */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int res;

        int _t_cases = Integer.parseInt(in.nextLine());
        for (int _t_i = 0; _t_i<_t_cases; _t_i++) {
            String _a = in.nextLine();
            res = stringReduction(_a);
            System.out.println(res);
        }
    }
}
