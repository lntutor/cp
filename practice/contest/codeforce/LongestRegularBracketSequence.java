//http://codeforces.com/contest/5/problem/C
//https://discuss.codechef.com/questions/23033/longest-regular-bracket-sequence

import java.io.IOException;
import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine();
        long subString = 0;
        long currentMax = Integer.MIN_VALUE;
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);
        for (int i = 0; i < line.length(); i++) {
            char item = line.charAt(i);
            if (item == '(') {
                stack.push(i);
            } else { // ')'
                if (stack.peek() !=-1 && line.charAt(stack.peek()) == '(') {
                    stack.pop();
                    if (i - stack.peek() > currentMax) {
                        currentMax = i - stack.peek();
                        subString = 1;
                    } else if (i - stack.peek() == currentMax) {
                        subString++;
                    }

                } else {
                    stack.push(i);
                }
            }
        }
        if (currentMax>0)
            System.out.println(currentMax + " " + subString);
        else
            System.out.println("0 1");
    }
}